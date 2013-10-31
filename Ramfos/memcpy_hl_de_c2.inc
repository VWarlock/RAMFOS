memcpy_hl_de_c2:ldax	d
		mov	m, a
		inr	l
		inr	e
		ldax	d
		mov	m, a
		inr	l
		inr	e
		dcr	c
		jnz	memcpy_hl_de_c2
		ret
