;----------------------------------------------------------------------------
; RAMFOS
; Ускоренная функция выводе символа на экран.
;
; На входе:
;  с - символ
;
; 2013-11-01 Разработано vinxru
;----------------------------------------------------------------------------

printChar:	push	h
		push	d
		push	b
		push	psw
printChar_pol:	 call	printChar_int
		pop	psw
popa_ret:	pop	b
		pop	d
		pop	h
		ret

; ---------------------------------------------------------------------------

printCharAll:	lhld	v_cursorPos		
		jmp	printChar_0

; ---------------------------------------------------------------------------

printChar_int:	
#if NO_PRINTER==0
		; Если включен эхо режим на принтер
		lda	v_printerEcho
		cpi	0D2h
		cz	doPrinterEcho
#endif
		; hl - положение курсора в пикселях		
		lhld	v_cursorPos		

		; Служебные символы
		mov	a, c		; Символ		
		cpi	1Fh
		jz	clearScreen

		; Если символ >0x1F, пропускаем проверки ниже
		jnc	fast		

		cpi	18h
		jz	cursorRight
		cpi	8
		jz	cursorLeft
		cpi	19h
		jz	cursorUp
		cpi	1Ah
		jz	cursorDown
		cpi	0Ch
		jz	loc_CE4B
		cpi	0Ah
		jz	cursorCrLf
		cpi	1Bh
		jz	printChar_esc
		cpi	7
		jz	keySound
		cpi	0Dh
		jz	saveCursorPosX0
				
fast:		; Если меньше 0x60, переходим к печати
		cpi	60h
		jc	printChar_0

		; Символы меньше 0x80 
		cpi	80h
		jc	printChar_koi

		; Промежуток C0-FF преобразовать в 80-BF
		sui	40h
		jm	loc_CBF1

		; Промежуток 80-BF преобразовать в 1-40
		sui	3Fh		

		; Обрабатываем промежуток 87-BF
		cpi	8
		jnc	printChar2
		mov	c, a

		; Промежуток 80-86 преобразовать в символы 1-7
		
loc_CBE2:	; Если меньше 0x60, переходим к печати
		cpi	60h
		jc	printChar_0

		; Трансляция из KOI-7 в KOI-8
printChar_koi:	lda	v_koi8
		ora	a
		jz	printChar_0
		mov	a, c
		adi	40h		

loc_CBF1:	mov	c, a

printChar_0:	; Если cursorX >= 190, то перевод строки
		mov	a, h
		cpi	190
		cnc	cursorCrLf

		; Увеличиваем положение курсора
		mov	a, h
		adi	3
		sta	v_cursorPos+1	; Положение курсора в пикселях

		; Положение курсора в DE
		xchg

		; Расчет адреса символа и знакоместа
		call	calcCharAddr3

		; Косяк в координатах
		mov	a, e
		sbi	8
		mov	e, a

		mvi	b, 9

		; Дублировать строку?
		XRA	A
		ORA	M
		LDA	v_clearScreenByte
		JP	drawCharDbl		
		 XRA	M
drawCharDbl:
		 		 
		dcx	h
		dcr c
		dcr c
		dcr c
		jz printCharS4
		dcr c
		jz printCharS2
		dcr c
		jz printCharS0

;----------------------------------------------------------------------------
; Сдвиг на 6

printCharS6:	CALL	printCharS6_0
printCharS6_0:	 RAR
		 RAR
		 RAR
		 RAR
		 PUSH	PSW
		  ANI	00000011b
		  MOV	C, A
		  LDAX	D
		  ANI	11111100b
		  XRA	C
		  STAX	D
		  INR	D
		 POP	PSW
		 RAR
		 ANI	11110000b
		 MOV	C, A
		 LDAX	D
		 ANI	00001111b
		 XRA	C
		 STAX	D
		 DCR	D
		 INX	D
		 INX	H
		 LDA	v_clearScreenByte
		 XRA	M
		 DCR	B
		JNZ	printCharS6_0
		JMP	drawChar_ll

;----------------------------------------------------------------------------
; Сдвиг на 0

printCharS0:    CALL	printCharS0_0
printCharS0_0:
		 ADD	A
		 ADD	A
		 MOV	C, A
		 LDAX	D
		 ANI	00000011b
		 XRA	C
		 STAX	D
		 INX	D
		 INX	H
		 LDA	v_clearScreenByte
		 XRA	M
		 DCR	B
		JNZ	printCharS0_0
		JMP	drawChar_ll
	
;----------------------------------------------------------------------------
; Сдвиг на 2

printCharS2:    CALL	printCharS2_0
printCharS2_0:	 ANI	03Fh
		 MOV	C, A
		 LDAX	D
		 ANI	11000000b
		 XRA	C
		 STAX	D
		 INX	D
		 INX	H
		 LDA	v_clearScreenByte
		 XRA	M
		 DCR	B
		JNZ	printCharS2_0
		JMP	drawChar_ll

;----------------------------------------------------------------------------
; Сдвиг на 4

printCharS4:	CALL	printCharS4_0
printCharS4_0:	 RAR
		 RAR
		 PUSH	PSW
		  ANI	00001111b
		  MOV	C, A
		  LDAX	D
		  ANI	11110000b
		  XRA	C
		  STAX	D
		  INR	D
		 POP	PSW
		 RAR
		 ANI	011000000b
		 MOV	C, A
		 LDAX	D
		 ANI	000111111b
		 XRA	C
		 STAX	D
		 DCR	D
		 INX	D
		 INX	H
		 LDA	v_clearScreenByte
		 XRA	M
		 DCR	B
		JNZ	printCharS4_0

;----------------------------------------------------------------------------

drawChar_ll:	DCX	H
		XRA	A
		ORA	M
		LDA	v_clearScreenByte
		JP	drawCharDbl2
		 XRA	M
drawCharDbl2:	INR	B
		RET

;----------------------------------------------------------------------------
    
printChar2:    sui	21h
		jnc	setColorChar
		adi	19h
		jz	popColor	; 87h Восстановние кода цвета из стека
		dcr	a
		jz	pushColor	; 88h Запоминание кода цвета по принципу стека (глубина 2 цвета)
		dcr	a
		jz	inverseColor	; 89h Инверсия кода цвета
		dcr	a
		jz	changeInverse	; 8Ah Инверсия фона чернобелого экрана (инверсия инверсии)
		dcr	a
		jz	setInverseNeg	; 8Bh Установка светлого фона черно-белого экрана (потому что A=0 будет инвертировано)
		dcr	a
		jz	setInverse	; 8Сh Установка темного фона черно-белого экрана (потому что A=0)
		dcr	a
		jz	pushCursorLine	; 8Dh Запоминание курсора строки
		dcr	a
		jz	popCursorLine	; 8Eh Восстановление курсора строки
		dcr	a
		jz	clearTopLine	; 8Fh Очистка верхней служебной строки
		dcr	a
		jz	clearBottomLine	; 90h Очистка нижней служебной строки
		dcr	a
		jz	scrollDown	; 91h Сдвииг экрана вних от курсора
		dcr	a
		jz	scrollUp	; 92h Сдвин экрана вверх от курсора
		dcr	a
		jz	pushCursor	; 93h Запоминание курсора экрана
loc_CCC1: 	dcr	a
		jz	popCursor	; 94h Восстановление курсора экрана
		dcr	a
		jz	printFileName	; 95h Вывод имени файла загруженного с диска
		dcr	a
		xchg
		lhld	v_koi8
		dcr	a
		jz	c_koi7		; 97h Включение режиме KOI-7
		dcr	a
		jz	c_koi8		; 98h Включение режиме KOI-8
		dcr	a
		dcr	a
		rnz			; Выход, а дальше 9Ah Сдвиг экрана вверх от нижней служеюной строки до текущей строки курсора
		xchg
		push	h
		inr	l
		inr	l
		mov	a, l
		adi	0Ah
		mov	e, a
		lda	v_screenHeight
		jmp	c_scrolUpEx

; ---------------------------------------------------------------------------

printChar_esc:	lxi	h, printChar_esc1		
		jmp	setEscMode
		
; ---------------------------------------------------------------------------

printChar_esc1:	; Обработка первого символа ESC-последовательности

		; Если символ Y, перейти к обработке второго символа
		mov	a, c
		cpi	'Y'
		lxi	h, printChar_esc2
		jz	setEscMode

		lhld	v_cursorPos
		call	printChar_0

setEscMode0:	lxi	h, printChar_int
setEscMode:	shld	printChar_pol+1
		ret

; ---------------------------------------------------------------------------

printChar_esc2:	; Вычесть из буквы 20h
		mov	a, c
		sui	20h
		sta	v_escRow
		lxi	h, printChar_esc3
		jmp	setEscMode		

; ---------------------------------------------------------------------------

printChar_esc3:	; Вычесть из буквы 20h
		mov	a, c
		sui	20h
		mov	l, a
		lda	v_escRow
		mov	h, a
		call	setCursorPos
		jmp	setEscMode0
		