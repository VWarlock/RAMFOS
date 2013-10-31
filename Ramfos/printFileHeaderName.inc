printFileHeaderLight:
		; Если сделать курсор цветным, то цвет будет задевать рамку. 

		; Инверсия
		mvi	a, C_INVERSE
		call	j_printCharA

printFileHeaderDark:
		; Функция сохранит положение курсора строки, но не восстановит его
		; Выведет на экран имя файла
		; После вывода имени функция установит темный фон
		call	printFileHeaderName2

popCursorLine2:	; Восстановить курсор строки
		mvi	a, C_POPCURSORL
		jmp	j_printCharA

; ---------------------------------------------------------------------------
; Функция сохранит положение курсора строки, но не восстановит его
; Выведет на экран имя файла
; После вывода имени функция установит темный фон

printFileHeaderName2:
		call	pushCursorLine2
		call	j_getCursorPos
		xchg

printFileHeaderName:
		mvi	c, 12
		lxi	h, v_header_name
printFileHeaderName_0:
		 mov	a, m
		 inx	h
		 call	j_printCharA
		 dcr	c
		jnz	printFileHeaderName_0

		; Установка темного фона
		mvi	a, C_NORMAL
		jmp	j_printCharA