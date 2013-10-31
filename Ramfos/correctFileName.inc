;----------------------------------------------------------------------------
; RAMFOS
; Вывести имя файла на экран и удалить из него все недопустимые символы
;
; 2013-11-01 Дизассемблировано vinxru
;----------------------------------------------------------------------------

printFileName:	; Разделитель
#if NICE
		call	printStringEx
		.db C_INVERSE, ' ', 0
#else
		mvi	c, 11h
		call	printChar
#endif

correctFileName:lxi	h, v_header2_name	; Имя
		mvi	b, 12			; Длина имени
correctFileN_1:	 mov	a, m
		 ; Символы меньше 0x20 заменяем на пробел
		 cpi	20h
		 jc	correctFileN_2
		 ; Символы от 0x20 до 0x7E допускаются
		 cpi	7Fh
		 jc	correctFileN_3
		 ; Символы от 0xC0 до 0xFF допускаются
		 cpi	0C0h
		 jnc	correctFileN_3		 
correctFileN_2:	 ; Заменяем недопустимый символ на пробел
		 mvi	m, 20h
		 mov	a, m
correctFileN_3:	 ; Выводим символ на экран
		 call	printCharA
		 ; Следующий символ
		 inx	h
		 dcr	b
		jnz	correctFileN_1		

		; Разделитель
#if NICE
		mvi	c, ' '
		jmp	printChar
#endif
		; Переход на printChar6