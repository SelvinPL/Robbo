	.title			"TILES HELPERS ASM"
	.module			tiles_helpers_asm
	.area			_CODE_1
	STATF_BUSY      = 0b00000010 ; When set, VRAM access is unsafe
	.STAT           = 0x41  ; LCD status
	.SCRN0          = 0x9800
	.globl			_map_to_tiles_lo		
	.globl			_map_to_tiles_hi

.macro WAIT_STAT ?lbl
lbl:
	ldh		a,		(.STAT)
	; Check if in LCD modes 0 or 1
	and		#STATF_BUSY
	jr		NZ,		lbl
.endm

.macro put_2_on_2_tile ;b - tile, hl addres, de addres + 32
	WAIT_STAT
	ld		a,		b
	ld		(hl+),	a
	inc		a
	ld		(hl+),	a
	add		hl,		de
	inc		a
	ld		(hl+),	a		
	inc		a
	ld		(hl),	a
.endm

.macro set_bkg_tile_xy_2_map_to_tiles ;e - low, a - hi, b - tile
	ld		c,		#0xf		;in fact x is in first 4 bits of low and y is (hi & 0x1) << 4 | low >> 4 but since it's page aligned we can do hi & 0xf
	and		c					;_______y yyyyxxxx
	ld		h,		a
	ld		a,		e
	and		#0xf0
	ld		l,		a
	add		hl,		hl			;y =* 4 but still at _____?y?yy yyyy0000
	add		hl,		hl
	ld		a,		e
	and		c					;
	add		a					;x *= 2
	add		l
	ld		l,		a			;now we should add carry to h
	xor		a,		a
	ld		d,		a
	adc		h
	and		#3					;we need to get rid of eventually 3 bit of hi
	add		#>.SCRN0			;and add to hi of tiles address 
	ld		h,		a			
	ld		a,		c
	add		c
	ld		e,		a
	put_2_on_2_tile
.endm


_set_bkg_tile_xy_2_map_to_tiles_with_translation:: 
	ld		a,		(de)
	and 	#0x7f
	ld		l,		a
	ld 		a, 		(_map_to_tiles_lo)
	add 	a,		l
	ld		l,		a
	ldh		a,		(_map_to_tiles_hi)		;efectivly in map_to_tiles_hi is hi part of address of current map_to_tiles and since it's size is 256 we can add l
	ld		h,		a						;to get what we want which is map_to_tiles[l]
	ld		b,		(hl)					;b - tile hl - addres
	ld		a,		d
	;e - low, a - hi, b - tile
	set_bkg_tile_xy_2_map_to_tiles
	ret