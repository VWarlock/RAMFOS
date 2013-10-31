;----------------------------------------------------------------------------
; RAMFOS
; Чтение первых 15 байт заголовка файла в v_header и вывод его на экран
; Потом чтение длины тела (первые 2 байта) в DE
;
; 2013-11-01 Дизассемблировано vinxru
;----------------------------------------------------------------------------

tapeReadHeader:	lxi	h, v_header
		call	tapeReadH_1

		; Длина не контроллируется!

		; Читаем 15 байт с магнитофона по адресу hl
		mvi	e, 15
tapeReadH_0:	 call	j_tapeRead
		 mov	m, a
		 inx	h
		 dcr	e
		jnz	tapeReadH_0

		; Выводим имя на экран
		call	printFileHeaderName

tapeReadH_1:	; Ждем пилот тон
		call	j_tapeReadPilot

		; Читаем слово в DE
		cnc	j_tapeRead
		mov	e, a
		cnc	j_tapeRead
		mov	d, a
		ret
