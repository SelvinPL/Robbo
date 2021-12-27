		.title			"TILES HELPERS ASM"
		.module			tiles_helpers_asm
		.area			_CODE
		.globl			_map_to_tiles_hi
		VDP_STAT		= 0xbf
		VDP_CMD			= 0xbf
		.VDP_CMD	    = 0xbf
		VDP_DATA       = 0xbe
		VDP_RSCY		= 0x89
		VDP_R10			= 0x8a
		VDP_R2			= 0x82
		VDP_TILEMAP		= 0x7800
		R2_MAP_0x3000	= 0xfd
		R2_MAP_0x3800	= 0xff
		STATF_INT_VBL	= 0b10000000
		.globl			.vbl_done

.macro set_tile_map_address address
	ld	a, address
	out	(VDP_CMD), a
	ld	a, #VDP_R2
	out	(VDP_CMD), a
.endm
		
_INT_ISR::
	ex af,af';'
	in a, (VDP_STAT)
	and #STATF_INT_VBL
	jr z, hbl$
vbl$:
	ld a, #1
	ld (.vbl_done), a
	jr end$
hbl$:
.rept 22
	nop
.endm
	set_tile_map_address #R2_MAP_0x3000
end$:
	ex af,af';'
	ei
	reti

.wait_vbl_done_alt::
_wait_vbl_done_alt::
		xor a
		ld (.vbl_done), a
wait$:
		halt
		ld a, (.vbl_done)
		or a
		jr z, wait$
		ret

.macro put_2_on_2_tile ;a - tile, hl addres, de addres + 64
	ld		c,		#VDP_CMD
	di
	out		(c),	l
	out		(c),	h
	dec		c
	out		(c),	a		;11
	wait_read_write	4		;4*
	in		l,		(c)		;skip
	wait_read_write 3
	inc		a
	out		(c),	a
	wait_read_write 3
	inc		a
	inc		c
	out		(c),	e
	out		(c),	d
	dec		c
	out		(c),	a
	wait_read_write 4
	in		l,		(c)  ;skip
	wait_read_write 3
	inc		a
	out		(c),	a
	ei
.endm


_set_bkg_tile_xy_2::
	pop		hl          ; HL = ret
	pop		de          ; DE = YX
	dec		sp
	ex		(sp),	hl     ; HL = data
	ex		de,		hl
	add		hl,		hl
	ex		de,		hl
	ld		a,		d
	ld		b,		#28
modcheck$:
	sub		b
	jr		NC,		modcheck$
	add		b
	rrca                    ; rrca(2) == rlca(6)
	rrca 
	ld		d,		a
	and		#0x07

	ld		bc,		#VDP_TILEMAP
	add		b
	ld		b,		a
	ld		a,		#0xC0
	and		d
	sla		e
	add		e
	ld		d,		b 
	ld		l,		a
	add		a,		#64
	ld		e,		a
	ld		a,		h
	ld		h,		d
	put_2_on_2_tile
	ret