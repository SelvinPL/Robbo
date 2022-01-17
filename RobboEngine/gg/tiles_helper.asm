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

.macro wait_read_write n
	.rept n
		nop
	.endm
.endm

.macro put_2_on_2_tile ?end;b - tile, hl addres, de address + 64
	ld		c,		#VDP_CMD
	ld		a,		i
	push	af
	di
	out		(c),	l
	out		(c),	h
	dec		c				;VDP_CMD -> VDP_DATA
	out		(c),	b		;11
	wait_read_write	4		;4*
	in		l,		(c)		;skip
	wait_read_write 3
	inc		b
	out		(c),	b
	wait_read_write 2
	inc		b
	inc		c				;VDP_DATA -> VDP_CMD
	out		(c),	e
	out		(c),	d
	dec		c				;VDP_CMD -> VDP_DATA
	out		(c),	b
	wait_read_write 4
	in		l,		(c)  ;skip
	inc		b
	pop		af
	out		(c),	b
	jp		po,		end
	ei
end:
.endm

.macro set_bkg_tile_xy_2 ?modcheck ;DE = YX, H  = data
	ld		a,		d
	ld		b,		#28
modcheck:
	sub		b
	jr		NC,		modcheck
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
	ld		b,		h
	ld		h,		d
	put_2_on_2_tile
.endm

_set_bkg_tile_xy_2::
	pop		hl          ; HL = ret
	pop		de          ; DE = YX
	dec		sp
	ex		(sp),	hl     ; HL = data
	ex		de,		hl
	add		hl,		hl
	ex		de,		hl
	set_bkg_tile_xy_2
	ret

_set_bkg_tile_xy_2_map_to_tiles_with_translation::
	pop		hl          ; HL = ret
	ex		(sp),	hl     ; HL = address
	ld		e,		l
	ld		d,		h
	ld		l,		(hl)
	ld		a,		(_map_to_tiles_hi)
	ld		h,		a
	ld		h,		(hl)
	ld		l,		e
	ex		de,		hl

	ld		a,		l
	and		#0xf0
	ld		c,		a
	ld		a,		h
	and		#1
	add		a,		c

	rrca
	rrca
	rrca
	rrca

	ld		h,		a
	ld		a,		l
	and		#0xf
	ld		l,		a
	add		hl,		hl
	ex		de,		hl
	set_bkg_tile_xy_2 ;DE = YX, H  = data
	ret