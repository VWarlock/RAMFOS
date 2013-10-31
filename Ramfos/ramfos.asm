; ===========================================================================
; ���������

STD_RAMFOS = 0				; ��������஢��� �⠭����� RAMFOS

#if STD_RAMFOS==0

DATE_IN_RAM		= 1		; 0      �������� ���� � �᭮���� ����⨢��� ����� (�������� ࠡ�� ��� ����)
NO_ROM_ENTRY		= 1		; 0      �⠭����� �ணࠬ�� � ���� 䠩���
NO_PRINTER		= 1		; 0 	 �⪫���� �ਭ��
NO_MXDOS		= 1		; 0 	 �⪫���� ����㧪� � ��᪥�� (� ��⭮c� MXDOS)
SD_ENABLED		= 0		; 0      ����祭� �����প� SD �����
OPEN_ANY_FILE		= 1		; 0 	 ���뢠�� 䠩� � ��� ���७��� (� �� ⮫쪮 TXT � ।����)
ALL_CHARS		= 1		; 0	 ����� ��� ᨬ����� ������������ �१ ESC
RKS_LOADER		= 1		; 0      ����᪠�� RKS 䠩��
BIG_ROM			= 1		; 0 	 �ᯮ�짮���� �� 64 �� ��� ���樠���� ��2 ��� ROM-���
WORK_WITHOUT_ARAM	= 47		; 0      �᫨ ���� �� �������, � �ᯮ�짮���� ���� � ��� ࠧ��஬ � ��� ��६�����
ROM_PAGE_START		= 01880h	; 04000h ���� ���� ��࠭��� ���
ROM_PAGE_END		= 0		; 0C000h ��᫥���� ���� ��࠭��� ��� + 1
CURSOR_BLINK_SPEED	= 767		; 767    ����প� ������� �����
ARAM_MAX_PAGE           = 0Fh		; 6      ���ᨬ��쭮� ���-�� ��࠭�� ���७��� ����� (���ᨬ� 0Fh)
ARAM_PAGE_END		= 0FFBBh        ; 0FFBBh ����� ��࠭��� ���� (36 ���� ���ᯮ��㥬��� ��� ��᫥)
DLG_START_PAGE		= 80h		; 0      �� ����᪥ �������� ��� ��࠭���
INIT_SCREEN_COLOR	= 0F1h		; 100h	 ����, ����� ���������� �࠭ �� ���樠����樨. 100h - ���������� ⥪�騬 梥⮬, ����� �� ⥯��� ��१���㧪� ����� ���� ���.
FAST_PRINT		= 1		; 0      ������ �㭪�� �뢮�� ⥪��. ��� �� �뢮��� ⥪�� ��ப� ��� ࠧ�뢮�. � �� ����� 梥� ᨬ����� �ࠢ��.
TRUE_CHECK_ARAM		= 1		; 0      �ᯯࠢ������ �㭪�� ��।������ ��쥬� ����
NICE			= 1		; 0	 ���� ����䥩�
COLOR_SUPPORT		= 1		; 0	 ��⠭���� 梥� �� 㬮�砭�� �� ���⪥ �㦥���� ��ப � �࠭�
NO_PRINT_STATUS_BUG	= 1		; 0	 ��ࠢ��� �訡��
DLG_CURSOR_AT_TOP	= 0		; 0	 ����� �� ��ࢮ� 䠩��
NO_ROM_SWITCH_BUG	= 1		; 0	 ����� �뫮 ����� �� �㫥��� ��࠭��� ���
RELOCATE_FILE_FUNCTIONS = 1		; 0      ��७��� ������� �㭪樨 �� F800 � C800, ���� ��� �� �������

#else

DATE_IN_RAM		= 0
NO_ROM_ENTRY		= 0
NO_PRINTER		= 0
NO_MXDOS		= 0
OPEN_ANY_FILE		= 0
ALL_CHARS		= 0
RKS_LOADER		= 0
BIG_ROM			= 0
WORK_WITHOUT_ARAM	= 0
ROM_PAGE_START		= 04000h
ROM_PAGE_END		= 0C000h
CURSOR_BLINK_SPEED	= 767
ARAM_MAX_PAGE           = 6
ARAM_PAGE_END		= 0FFBBh
DLG_START_PAGE		= 0
INIT_SCREEN_COLOR	= 100h
FAST_PRINT		= 0
TRUE_CHECK_ARAM		= 0
NICE			= 0
COLOR_SUPPORT		= 0
NO_PRINT_STATUS_BUG	= 0
DLG_CURSOR_AT_TOP	= 0
NO_ROM_SWITCH_BUG	= 0
RELOCATE_FILE_FUNCTIONS = 0

#endif

; ===========================================================================
; ����� �����-������

IO_KEYB_A		= 0FFE0h
IO_KEYB_B		= 0FFE1h
IO_KEYB_C		= 0FFE2h
IO_KEYB_MODE		= 0FFE3h
IO_EXT_A		= 0FFE4h
IO_EXT_B		= 0FFE5h
IO_EXT_C		= 0FFE6h
IO_EXT_MODE		= 0FFE7h
IO_FLOPPY_CMD		= 0FFE8h
IO_FLOPPY_SECTOR	= 0FFEAh
IO_FLOPPY_DATA		= 0FFEBh
IO_TIMER		= 0FFECh
IO_FLOPPY_TRIG		= 0FFF0h
IO_FLOPPY_HEAD		= 0FFF2h
IO_COLOR		= 0FFF8h
IO_PAGE_RAM		= 0FFFCh
IO_PAGE_ARAM		= 0FFFDh
IO_PAGE_ROM		= 0FFFEh
IO_PAGE_STD		= 0FFFFh

; ===========================================================================
; ����������� ���� ��������

C_BEEP		= 7
C_LEFT		= 8
C_CLEARSCREEN	= 1Fh
C_PUSHCOLOR	= 88h
C_POPCOLOR	= 89h
C_INVERSE	= 8Bh
C_NORMAL	= 8Ch
C_PUSHCURSORL	= 8Dh
C_TOPLINE	= 8Fh
C_POPCURSORL	= 8Eh
C_BOTTOMLINE	= 90h
C_PUSHCURSORS	= 93h
C_POPCURSORS	= 94h
C_SCROLLUPEX	= 9Ah

; ===========================================================================
; ��������� ������ ������

CHAR_HEIGHT	  	= 8
LINE_HEIGHT	 	= 10
SCREEN_HEIGHT	 	= 250
FILE_HEADER_SIZE	= 30
STACK_TOP		= 0D2FFh
RAM_TOP			= 8FFFh

; ===========================================================================
; ����������

.org 0C000h

charGen:

.include "chargen.inc"

keybMap:	.db 81h, 0ch, 19h, 1ah, 20h, 20h, 20h, 08h, 09h, 18h, 0ah, 0dh ; ������ ��ப� ����������
v_charGenPtr:	.dw charGen
v_keybMap:	.dw keybMap
		.db 51h, 5Eh, 53h, 4Dh,	49h, 54h, 58h, 42h, 40h, 2Ch, 2Fh, 5Fh ; Q^SMITXB@,/_
v_aramPageEnd:	.dw ARAM_PAGE_END
v_aramPageStart:.dw 0
		.db 46h, 59h, 57h, 41h,	50h, 52h, 4Fh, 4Ch, 44h, 56h, 5Ch, 2Eh; FYWAPROLDV\.
v_koi8:		.db 0	; ���-7=FF / ���-8=00
v_rusLat:	.db 0	; ���=FF / LAT=00
v_capsLock:	.db 0	; BP=00 / HP=02
v_printerEcho:	.db 0
		.db 4Ah, 43h, 55h, 4Bh, 45h, 4Eh, 47h, 5Bh, 5Dh, 5Ah, 48h, 3Ah ; JCUKENG[]ZH:
v_selColor:	.db 0B1h
v_aramMaxPage:	.db 0			; �����	��᫥���� ��࠭��� RAM-��᪠
v_cursorPos:	.dw 0			; ��������� ����� � ���ᥫ��
		.db 3Bh, 31h, 32h, 33h,	34h, 35h, 36h, 37h, 38h, 39h, 30h, 2Dh ; ;1234567890-
v_beepConfig:	.dw 0A05h
v_oldBeep:	.dw 0
		.db 1Bh, 8Ah, 0, 1, 2, 3, 4, 5,	6, 8Bh,	8Ch, 1Fh ; ������ ��ப� ����������
v_inverse:	.db 0
		.db 0
v_aramMaxPageI:	.db ARAM_MAX_PAGE
v_tapeMode:	.db '0'
v_tapePulseB:	.dw 322Ch	; 1200 ���
v_tapePulseA:	.dw 1812h
v_tapePulseB2:	.dw 211Bh	; 1800 ���
v_tapePulseA2:	.dw 0F09h
v_tapePulseB3:	.dw 1812h	; 2400 ���
v_tapePulseA3:	.dw 0B05h
v_tapePresets:

; ===========================================================================
; ���

.org 0C66Ch

.include "tapeReadPilot.inc"
.include "tapeWait.inc"
.include "tapeRead.inc"
.include "tapeWritePilot.inc"
.include "tapeWrite.inc"
.include "tapePulse.inc"
.include "strToHex.inc"
.include "calcCrc.inc"
.include "pushPopCursor.inc"
.include "setGetMemTop.inc"
.include "pushColor.inc"

#if $ > 0C800h
�訡��_����_C000_��_������
#endif
.org 0C800h

.include "c800.inc"
.include "cmp_hl_de.inc"
.include "inputFileName.inc"
.include "printFileName.inc"
.include "printCharA.inc"
.include "biosInit.inc"
.include "printString.inc"
.include "parseDate.inc"
#if TRUE_CHECK_ARAM
.include "checkARAM_v2.inc"
#else
.include "checkARAM.inc"
#endif
.include "inputDate.inc"
.include "topLine.inc"		; �த�������� � inverse
.include "inverse.inc"
.include "bottomLine.inc"
.include "input.inc"
.include "getCharFromScreen.inc"
.include "memcmp_hl1_de_c.inc"
.include "hl_div_2.inc"
.include "fullClearScreen.inc"
.include "printHex.inc"
#if FAST_PRINT
.include "printChar_fast.inc"
#else
.include "printChar.inc"
#endif
.include "calcCharAddr.inc"
#if FAST_PRINT!=1
.include "printChar2.inc"	; �த�������� � setCursorPos
#endif
.include "setCursorPos.inc"
.include "getCursorPos.inc"
.include "scrollUp.inc"
.include "memcpy_hl_de_c2.inc"
.include "cursor.inc"
.include "scrollDown.inc"
.include "memcpyb_hl_de_c2.inc"
.include "clearScreen.inc"
.include "clearLine.inc"
.include "keyWait.inc"
.include "keyCursor.inc"		
.include "keyCheck.inc"
.include "keyScan.inc"		; �த�������� � keySound
.include "keySound.inc"
.include "oldbeep.inc"
.include "delay_l.inc"
.include "beep.inc"
.include "capsLock.inc"
.include "tapeMode.inc"
.include "printerEchoMode.inc"
.include "printerHex.inc"
.include "printerEcho.inc"
.include "printer.inc"
.include "setColorChar.inc"
.include "setColor.inc"
.include "popColor.inc"
.include "bigRom.inc"
#if RELOCATE_FILE_FUNCTIONS
.include "fileSaveHeader.inc"	; �த������� � pageWriteBlock
.include "pageWriteBlock.inc"
#endif

.include "v_printerXlat.inc"

; �᫨ ��� ����, � �ᯮ������ ��� ������让 ����, �� �� ��� �� �
; ࠡ�⠫�.

#if WORK_WITHOUT_ARAM != 0
miniPage:
.org $ + FILE_HEADER_SIZE + WORK_WITHOUT_ARAM + 2	; ���࠭���� 䠩�� � WORK_WITHOUT_ARAM ����
miniPageEnd:
.db 8							; � �����뢠���� ���� �ନ����.
#endif

a_lat:		.db 04Ch, 041h, 054h, 0 ; "LAT"
a_rus:		.db 0F2h, 0F5h,	0F3h, 0	; "���"

#if NICE
a_inputFileName:.db ' ', 0C6h, 0C1h, 0CAh, 0CCh, 3Ah, ' ', C_PUSHCURSORL, 0 ; "䠩�" + ����������� ����� ��ப�
#else
a_inputFileName:.db 11h, 0C6h, 0C1h, 0CAh, 0CCh, 3Ah, C_PUSHCURSORL, C_BEEP, 0 ; "䠩�" + ����������� ����� ��ப�
#endif

A_INPUTDATE
A_INITSCREEN

; ===========================================================================
; ����������

#if $ > 0D1F0h
�訡��_����_C800_��_������
#endif
.org 0D1F0h

v_tape:		.dw 0

; ��������� 䠩�� 2

v_header2:	.db 0D3h, 0D3h, 0D3h		; ��� ������ ���� 0D3h, 0D3h, 0D3h, ���� �㭪�� ����㧪� 䠩�� �� ࠡ����. ���� �� ���樠������� �� ��६����!
v_header2_name:	.db ' ',' ',' ',' ',' ',' ',' ',' ',' '
v_header2_ext:	.db ' ',' ',' '
v_header2_saved:.db 8Bh			; �ਧ��� �� ��࠭������ 8B, 8C
v_header2_date:	.db 01h, 11h, 13h	; ���
		.db 0, 0, 0, 0, 0	; ����� MXDOS
v_header2_start:.dw 0
v_header2_end:	.dw 0
v_header2_crc:	.dw 0

; ����� ��������� 䠩��

v_dblClear:	.db 0
		.db 0,0,0,0,0,0,0,0,0
unk_D21A:	.db 0,0,0,0,0,0
v_pushCursorLn:	.dw 0
v_pushCursor:	.dw 0
v_escMode:	.db 0
v_key2:		.db 0
v_printerCrLf:	.db 0		
v_memTop:	.dw 0
v_key0:		.dw 0
v_key1:		.dw 0
v_oldSP:	.dw 0
		.db 0
v_topLineHeight:.dw 0
v_screenHeight:	.db 0		; ���� �࠭�
v_screenHeight1:.db 0		; ���� �࠭� - 10
v_bottomLineId:	.db 0
v_color:	.db 0		; ����騩 梥� 䮭� � �㪢
v_pushColor:	.dw 0
		.db 0,0,0,0
v_aramPageEnd2:	.dw 0
v_escRow:	.db 0
		.db 0
v_lastKey:	.db 0
		.db 0
		.db 0
v_pageStart:	.dw 0		; ��砫� ⥪�饩 ��࠭���
v_page:		.db 0		; ������ ��࠭��

		.db 0,0,0,0, 0,0,0,0, 0,0,0,0

; ��������� 䠩��
; ���� 15 ���� (v_header, v_header_name, v_header_ext) �⠥��� �㭪樥� tapeReadHeader
; ���� 30 ���� ������ �㭪樥� fileLoadHeader


v_header:	.db 0D3h, 0D3h, 0D3h	; �����䨪���, ������ ���� 0D3h, 0D3h, 0D3h
v_header_name:	.db ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
v_header_spc:	.db ' '
v_header_ext:	.db ' ', ' ', ' '
v_header_saved:	.db 0
v_header_date:	.db 0, 0, 0
v_header_unused:.db 0, 0, 0, 0, 0
v_header_start:	.dw 0
v_header_stop:	.dw 0
v_header_crc:	.dw 0

; ����� ��������� 䠩��

v_curFile:	.dw 0
v_printedFile:	.dw 0
f_nextFile:	.dw 0
f_fileBodySize:	.dw 0
f_fileSize:	.dw 0
v_pageFreeTotal:.dw 0
v_pageFreePtr:	.dw 0

		.db 0F0h, 77h, 23h, 1Bh, 7Ah, 0B3h, 0CAh, 95h, 0D2h, 0Ch, 0C2h, 78h, 0D2h, 22h, 0, 8Fh, 0EBh, 22h, 2, 8Fh, 0C3h, 52h, 0D2h

buffer:		.db 0,0,0,0,0,0,0,0,0	; �ᯮ������ ���ᨬ� 9 ᨬ����� ��� ����� ����. ��᫥���� ���� ��� ����஫� ��९�������

; ===========================================================================
; ���

.org 0F800h

.include "f800.inc"
.include "loadMXDOS.inc"
.include "fileFind.inc"
.include "pageNext.inc"
.include "fileFind1.inc"
.include "dialog.inc"		; �த������� � fileSaveHeader
#if RELOCATE_FILE_FUNCTIONS
	jmp	fileSaveHeader
#else
.include "fileSaveHeader.inc"	; �த������� � pageWriteBlock
.include "pageWriteBlock.inc"
#endif
.include "fileSetGetName.inc"
.include "fileSetType.inc"
#if NO_ROM_ENTRY | RKS_LOADER
.include "exec.inc"
#endif

; ===========================================================================
; ����������

a_defHeader:	.db 0D3h, 0D3h,	0D3h	; ��થ� ��砫� 䠩�� (�� ��� ��易⥫쭮 ������� ��� 12 �஡����)
a_12spaces:	.text "            "	; ���⮥ ���
a_exe:		.text "EXE"
a_com:		.text "COM"
a_copy:		.db 0CBh, 0CFh,	0D0h, 0C9h, 0D2h, 0CFh,	0D7h, 
		.db 0C1h, 0D4h, 0D8h, 0					; "����஢���"
a_deleteDate:	.db 0C4h, 0C1h,	0D4h, 0D5h, 20h				; "���� 㤠����"
a_delete:	.db 0D5h, 0C4h,	0C1h, 0CCh, 0C9h, 0D4h,	0D8h, 0		; "㤠����"
a_load:		.db 0DEh, 0D4h,	0C5h, 0CEh, 0C9h, 0C5h,	0		; "�⥭��"
a_save:		.db 0DAh, 0C1h,	0D0h, 0C9h, 0D3h, 0D8h,	0		; "������"
a_verify:	.db 0D3h, 0D2h,	0C1h, 0D7h, 0CEh, 0C9h,	0D4h, 0D8h, 0	; "�ࠢ����"
a_name:		.db 0C9h, 0CDh,	0D1h, 0					; ���

; ===========================================================================
; ���� ����������

.include "window.inc"

.end		