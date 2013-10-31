memcmp_ext:	lxi	d, v_header_ext

memcmp_hl_de_3:	mvi	c, 3

memcmp_hl_de_c:	 ; if(*de-- != *hl--) return;
		 ldax	d
		 cmp	m
		 inx	h
		 rnz
		 inx	d
		 dcr	c
		jnz	memcmp_hl_de_c
		ret
