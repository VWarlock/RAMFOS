;----------------------------------------------------------------------------
; RAMFOS
; Вывод символа на экран. Продолжение printChar.inc
;
; 2013-11-01 Дизассемблировано vinxru
;----------------------------------------------------------------------------

printChar2:	sui	21h
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

printChar_esc1:	; Обработка первого символа ESC-последовательности

		; Если символ Y, перейти к обработке второго символа
		mov	a, c
		cpi	'Y'
		mvi	a, 2
		jz	setEscMode

		; Доработка для вывода всех символов знакогенератора
#if ALL_CHARS
printCharAll:
		xra	a
		sta	v_escMode
		lhld	v_cursorPos
		jmp	printChar_0
#endif

; ---------------------------------------------------------------------------

setEscMode0:	xra	a
setEscMode:	sta	v_escMode
		ret

; ---------------------------------------------------------------------------

printChar_esc2:	sta	v_escRow
		mvi	a, 3
		jmp	setEscMode

; ---------------------------------------------------------------------------

setEscMode1:	mvi	a, 1
		jmp	setEscMode
		
; ---------------------------------------------------------------------------

printChar_esc:	; Обработка ESC последовательности

		; Если printChar_esc1Mode=1
		dcr	a
		jz	printChar_esc1
		mov	b, a

		; Вычесть из буквы 20h
		mov	a, c
		sui	20h

		; Если printChar_esc1Mode=2, сохранить 
		dcr	b
		jz	printChar_esc2

		mov	l, a
		lda	v_escRow
		mov	h, a
		call	setEscMode0