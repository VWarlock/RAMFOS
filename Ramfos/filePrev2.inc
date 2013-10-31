		; Начинаем поиск с начала
		call	fileSetPage
dlg_findPrev:    ; Загружаем файл
		 call	fileLoadHeader
		 jnz	0F800h
		 ; Следующий файл за ним, это наш?
		 pop	d
		 call	cmp_hl_de
		 push	d
		 ; Цикл
		 lhld	f_nextFile
		 jnz	dlg_findPrev
		; Файл найден
		lhld	v_curFile
