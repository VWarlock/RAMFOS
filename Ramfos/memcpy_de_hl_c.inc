memcpy_de_hl_c: mov	a, m
		stax	d
		inx	h
		inx	d
		dcr	c
		jp	memcpy_de_hl_c
		ret
