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

;b - tile, hl - addres, de - 30
.macro put_2_on_2_tile 
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

;b - tile, d - hi, e - low
.macro set_bkg_tile_xy_2_map_to_tiles 
	ld		h,		d			;nibbles of address are also x,y coords in format x+16*y (Nyyx) (as x is [0,16), and y [0, 32) )
	ld		l,		e			;we need to translate it to as we have 16x16 field 
	add		hl,		hl			;4*Nyyx
	add		hl,		hl
	ld		a,		e			
	and		#0xf				;get x
	add		a
	ld		c,		a			;2*x
	ld		a,		l
	sub		c					;and substract
	ld		l,		a
	ld		a,		h
	and 	a,		#3			;since buffer is 32x32
	add		#>.SCRN0			;and add to hi of tiles address 
	ld		h,		a
	ld		de,		#0x001e
	put_2_on_2_tile
.endm


_set_bkg_tile_xy_2_map_to_tiles_with_translation:: 
	ld		a,		(de)
	and 	#0x7f							;get rid of wait flag
	ld		l,		a
	ld 		a, 		(_map_to_tiles_lo)
	add 	a,		l
	ld		l,		a
	ldh		a,		(_map_to_tiles_hi)		;efectivly in map_to_tiles_hi is hi part of address of current map_to_tiles and since it's size is 128 we can add l
	ld		h,		a						;to get what we want which is map_to_tiles[l]
	ld		b,		(hl)					;b - tile hl - addres
	;b - tile, d - hi, e - low
	set_bkg_tile_xy_2_map_to_tiles
	ret