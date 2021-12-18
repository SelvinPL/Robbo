		.title  "TILES HELPERS ASM"
		.module tiles_helpers_asm

		.area _CODE
		;.globl _tiles_trans

		STATF_BUSY      = 0b00000010 ; When set, VRAM access is unsafe
		.STAT           = 0x41  ; LCD status

.macro WAIT_STAT ?lbl
lbl:
	ldh		a,		(.STAT)
	; Check if in LCD modes 0 or 1
	and		#STATF_BUSY
	jr		NZ,		lbl
.endm

	; TILE_TYPE(t)		((t) & 0xf)
	; TILE_SUB_TYPE(t)	((t) >> 0x4)
	; load t and translate  - tiles_trans[TILE_TYPE(t)][TILE_SUB_TYPE(t)]
_set_bkg_tile_xy_2_with_translation::
	ldhl	sp,		#4
	ld		a,		(hl)
	and		#0x0f
	ld		l,		a
	ld		h,		#0
	add		hl,		hl
	;ld		bc,		#_tiles_trans
	add		hl,		bc
	ld		a,		(hl+)
	ld		c,		a
	ld		b,		(hl)
	ldhl	sp,		#4
	ld		a,		(hl)
	swap	a
	and		#0x0f
	ld		h,		#0
	ld		l,		a
	add		hl,		bc
	ld		a,		(hl)
	ld		b,		a
	
	ldhl	sp,		#2
	; load x
	ld		a,		(hl+)
	; x*=2
	add		a
	ld		d,		a
	; load y
	ld		a,		(hl)
	; y*=2
	add		a
	ld		e,		#0x98 ;#0x98
	swap	a
	rlca
	ld		c,		a
	and		#3
	add		e
	ld		h,		a
	ld		a,		#0xe0
	and		c
	add		d
	ld		l,		a
	add		a,		#32
	ld		e,		a
	ld		d,		h

	WAIT_STAT
	ld		a,		b
	; load translated + 0
	ld		(hl+),	a
	; x++
	inc		a
	; load translated + 1
	ld		(hl),	a
	; x-- y+=32
	ld		h,		d
	ld		l,		e
	inc		a 
	; load translated + 2
	ld		(hl+),	a         
	; x++
	inc		a
	; load translated + 3
	ld		(hl),	a
	ret

_set_bkg_tile_xy_2::
	ldhl	sp,		#4
	ld		a,		(hl)
	ld		b,		a
	
	ldhl	sp,		#2
	; load x
	ld		a,		(hl+)
	; x*=2
	add		a
	ld		d,		a
	; load y
	ld		a,		(hl)
	; y*=2
	add		a
	ld		e,		#0x98 ;#0x98
	swap	a
	rlca
	ld		c,		a
	and		#3
	add		e
	ld		h,		a
	ld		a,		#0xe0
	and		c
	add		d
	ld		l,		a
	add		a,		#32
	ld		e,		a
	ld		d,		h

	WAIT_STAT
	ld		a,		b
	; load translated + 0
	ld		(hl+),	a
	; x++
	inc		a
	; load translated + 1
	ld		(hl),	a
	; x-- y+=32
	ld		h,		d
	ld		l,		e
	inc		a 
	; load translated + 2
	ld		(hl+),	a         
	; x++
	inc		a
	; load translated + 3
	ld		(hl),	a
	ret