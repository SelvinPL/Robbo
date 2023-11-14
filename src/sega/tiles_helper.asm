		.title			"TILES HELPERS ASM"
		.module			tiles_helpers_asm
		.area			_CODE
		.globl			_map_to_tiles_lo		
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
	ex af,af'
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
	ex af,af'
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

.macro put_2_on_2_tile ?end;d - tile, hl addres
	ld		c,		#VDP_CMD
	ld		a,		i
	push	af
	di
	out		(c),	l		;12
	out		(c),	h		;12
	ld		a,		d		;4
	dec		c				;4			VDP_CMD -> VDP_DATA
	out		(c),	a		;12
	ld		e,		#64		;7
	wait_read_write	2		;8+19=27
	in		e,		(c)		;12			skip
	ld		e,		#64		;7
	inc		a				;4
	wait_read_write 1		;4+23=27
	out		(#VDP_DATA),	a		;11
	inc		a				;4
	ld		d,		a		;4
	inc		c				;4          VDP_DATA -> VDP_CMD
	ld		a,		l		;4
	add		e				;4
	ld		l,		a		;4
	ld		a,		d       ;4+24=28
	out		(c),	l		;12
	out		(c),	h		;12
	dec		c				;4			VDP_CMD -> VDP_DATA
	out		(c),	a		;12
	ld		e,		#0		;7
	inc		a				;4
	ld		d,		a		;4+23=27
	in		e,		(c)		;12			skip
	pop		af				;10
	wait_read_write 1		;4+22=26
	out		(c),	d		;12
	jp		po,		end
	ei
end:
.endm

.macro set_bkg_tile_xy_2 ?modcheck ;HL = YX, D  = data
	ld		a,		h
	ld		b,		#28
modcheck:
	sub		b
	jr		NC,		modcheck
	add		b
	rrca                    ; rrca(2) == rlca(6)
	rrca 
	ld		e,		a
	and		#0x07

	ld		b,		#>VDP_TILEMAP

	add		b
	ld		h,		a
	ld		a,		#0xC0
	and		e
	sla		l
	add		l
	ld		l,		a
	put_2_on_2_tile
.endm

_set_bkg_tile_xy_2_map_to_tiles_with_translation::
	ld		e,		l
	ld		d,		h
	ld		a,		(hl)
	and 	#0x7f
	ld		l,		a
	ld 		a, 		(_map_to_tiles_lo)
	add 	a,		l
	ld		l,		a
	ld		a,		(_map_to_tiles_hi)
	ld		h,		a
	ld		h,		(hl)
	
	ld		a,		e
	and		#0xf0
	ld		c,		a
	ld		a,		d
	and		#1
	add		a,		c

	rrca
	rrca
	rrca
	rrca

	ld		d,		h
	ld		h,		a
	ld		a,		e
	and		#0xf
	ld		l,		a
	add		hl,		hl
	set_bkg_tile_xy_2 ;HL = YX, D  = data
	ret