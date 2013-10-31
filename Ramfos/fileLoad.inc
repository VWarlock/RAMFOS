fileLoad:	; Подменяем адрес загрузки в заголовке файла
		; de = v_header_start = hl; v_header_stop = f_fileBodySize + hl;
		call	fileChangeAddr

		jmp	fileLoadCom

; ---------------------------------------------------------------------------

#if RKS_LOADER
fileLoadNoCheck:; bc - длина файла
		; hl - адрес тела файла в ДОЗУ
		lhld	f_fileBodySize
		push	h
		 lhld	v_curFile ; указатель на заголовок
		 lxi	b, 30	; длина заголовка
		 dad	b
		pop	b

		; Читаем bc байт из ДОЗУ по адресу hl в ОЗУ по адресу de
		jmp	pageReadBlock ; hl-диск,de-память,bc-длина-1

; ---------------------------------------------------------------------------
		
fileLoad2:	lhld	v_header_start
		xchg
#endif

; Должен быть загружен заголовок
; На выходе должно быть de = v_header_start

fileLoadComEx:	; Вывод сообщения "Ждите!"
		call	printStringEx
		.db 8Eh, 8Bh, 20h, 0D6h, 0C4h, 0C9h, 0D4h, 0C5h, 21h, 20h, 8Eh, 0

fileLoadCom:
#if RKS_LOADER
		call	fileLoadNoCheck
#else
		; bc - длина файла
		; hl - адрес тела файла в ДОЗУ
		lhld	f_fileBodySize
		push	h
		 lhld	v_curFile ; указатель на заголовок
		 lxi	b, 30	; длина заголовка
		 dad	b
		pop	b

		; Читаем bc байт из ДОЗУ по адресу hl в ОЗУ по адресу de
		call	pageReadBlock ; hl-диск,de-память,bc-длина-1#endif
#endif
		; Расчитываем контрольную сумму от v_header_start до v_header_stop
		dcx	d
		lhld	v_header_start
		call	j_calcCrc

		; Сравнить bc и v_header_crc
		push	b
		pop	d		
		lhld	v_header_crc
		call	j_cmp_hl_de

		; de=v_header_stop, hl=v_header_start
		jmp	loadDStartDStop
