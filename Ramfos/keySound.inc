;----------------------------------------------------------------------------
; RAMFOS
; Звуковой сигнал при нажатии клавиши
;
; 2013-11-01 vinxru
;----------------------------------------------------------------------------

keySound:	push	b
		 xchg
		 lhld	v_beepConfig
		 xchg

		 lda	v_rusLat
		 ani	1
		 mov	a, d
		 jnz	keySound_0
		  rrc
keySound_0:	 mov	d, a

		 mov	b, e
		 mov	c, e
		 ora	a
		 call	setTimer
		pop	b

		mvi	a, 0FFh
		ret
