;----------------------------------------------------------------------------
; RAMFOS
; Запуск RKS файла
;
; 2013-11-01 Разработано vinxru
;----------------------------------------------------------------------------

#if RKS_LOADER
		; Это RKS файл
		lxi	h, a_rks
		call	memcmp_ext
		jnz	defExec2
		
		; Загрузить его в память
		call	fileLoad2
		jnz	dlg_error

		; Найти файл Monitor2.sys в ПЗУ
		push	h
		 lxi	h, a_monitor2_sys
		 call	exec1
		pop	h

		jnz	dlg_error
		
		; Что бы не испортить стек
		lxi	sp, 8FFFh

		; Адрес программы
		push	h
		jmp	exec2

a_rks:		.db "RKS"
a_monitor2_sys:	.db "Monitor2 SYS"

defExec2:
#endif