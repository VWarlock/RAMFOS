memcmp_hl1_de_c: ; if(*de-- != *--hl) return;
		 ldax	d
		 dcx	d
		 dcx	h
		 cmp	m
		 rnz
		 ; c--
		 dcr	c
		 rz
		jmp	memcmp_hl1_de_c
