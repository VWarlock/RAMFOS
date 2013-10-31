;----------------------------------------------------------------------------
; RAMFOS
;
; 2013-11-01 vinxru
;----------------------------------------------------------------------------                   

; DE = v_header2_start
; HL = v_header2_size-1

fileGetStartAndSize:
		lhld	v_header2_start
		xchg
		lhld	v_header2_end
		; Продолжение на subHlDe
