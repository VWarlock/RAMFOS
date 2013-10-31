;+---------------------------------------------------------------------------
; RAMFOS
; ������������� ��������� ������ � ����� � �����
;
; �� �����:
;  de - ������
;
; 2013-11-01 ����������������� vinxru
;----------------------------------------------------------------------------

parseDate:	; ����
		call	strToHex
		mov	a, l
#if DATE_IN_RAM
		sta	v_header2_date+0
#else
		sta	parseDate_r1+1
#endif
		rc
		; �����
		call	strToHex
		mov	a, l
#if DATE_IN_RAM
		sta	v_header2_date+1
#else
		sta	parseDate_r2+1
#endif
		rc
		; ���
		call	strToHex
		mov	a, l
#if DATE_IN_RAM
		sta	v_header2_date+2
#else
		sta	parseDate_r3+1
#endif
		rc
		; ������� ����� ����������
		jmp	xra_a_stc_ret