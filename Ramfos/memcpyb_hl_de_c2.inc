memcpyb_hl_de_c2:
		dcr	l
		dcr	e
		ldax	d
		mov	m, a

		dcr	l
		dcr	e
		ldax	d
		mov	m, a

		dcr	c
		jnz	memcpyb_hl_de_c2
		ret
