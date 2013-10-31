printHexWord:	mov	a, h
		call	j_printHex
		mov	a, l
		call	j_printHex
		jmp	j_printChar