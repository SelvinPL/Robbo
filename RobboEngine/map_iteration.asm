		.title  "MAP ITERATION ASM"
		.module map_iteration_asm

		.area _CODE

		FIELD_WALL		=	'!'
		FIELD_EMPTY		=	' '


_mapIterationASM::
;chanegesPtr = chaneges;
	ld	hl, #_chanegesPtr
	ld	(hl), #<(_chaneges)
	inc	hl
	ld	(hl), #>(_chaneges)
;for (iterY = changeYstart; iterY < changeYend; iterY++)
	ldh	a, (#_changeYstart)
	ldh	(#_iterY),a
inc124$:
	ld	hl, #_changeYend
	sub	a, (hl)
	jp	NC, inc121$
;doChanege = BETWEEN(iterY, map_pos_y == 0 ? 0 : map_pos_y - 1, map_pos_y + 9);
	ldh	a, (#_map_pos_y)
	ld	d, a
	or	a, a
	jr	Z, inc131$
	dec	a
inc131$:
	ld	c, a
	ldh	a, (#_iterY)
	ld	e, a
	sub	a, c
	jr	C, inc128$
	ld	a, d
	add	a, #0x09
	sub	a, e
	jr	NC, inc129$
inc128$:
	xor	a, a
	jr	inc130$
inc129$:
	ld	a, #0x01
inc130$:
	ldh	(#_doChanege),a
;y_next_tilesPtr = y_next_tiles - 1;
	ld	hl, #_y_next_tilesPtr
	ld	a, #<((_y_next_tiles - 1))
	ld	(hl+), a
	ld	(hl), #>((_y_next_tiles - 1))
;for (iterX = 0; iterX < 16; iterX++)
	xor	a, a
	ldh	(_iterX), a
inc122$:
;y_next_tilesPtr++;
	ld	hl, #_y_next_tilesPtr
	inc	(hl)
inc203$:
;if (*++mapPtr == FIELD_WALL)
	ld	hl, #_mapPtr
	inc	(hl)
	jr	NZ, inc204$
	inc	hl
	inc	(hl)
inc204$:
	ld	hl, #_mapPtr
	ld	a, (hl+)
	ld	c, a
	ld	b, (hl)
	ld	a, (bc)
	cp	a, #FIELD_WALL
	jp	Z,inc119$
;if (*mapPtr == FIELD_EMPTY)
	cp	a, #FIELD_EMPTY
	jr	NZ, inc117$
;if (*y_next_tilesPtr != FIELD_NONE)
	ldh	a, (#_y_next_tilesPtr)
	ld	l, a
	ld	h, #0xff
	ld	a, (hl)
	or	a, a
	jr	Z, inc110$
;*mapPtr = *y_next_tilesPtr;
;*y_next_tilesPtr = FIELD_NONE;
	ld	(bc), a
	xor	a, a
	ld	(hl), a
;if (doChanege)
	ldh	a, (#_doChanege)
	or	a, a
	jp	Z, inc119$
;*chanegesPtr++ = iterX;
	ldh	a, (#_chanegesPtr)
	ld	c, a
	ld	b, #0xc2
	ldh	a, (#_iterX)
	ld	(bc), a
;*chanegesPtr++ = iterY;
	inc c
	ldh	a, (#_iterY)
	ld	(bc), a
	ld	a, c
	inc a
	ldh	(#_chanegesPtr), a
	jr	inc119$
inc110$:
;else if (x_next_tile != FIELD_NONE)
	ldh	a, (#_x_next_tile)
	or	a, a
	jr	Z, inc119$
;*mapPtr = x_next_tile;
	ld	(bc), a
;x_next_tile = FIELD_NONE;
	xor a, a
	ldh	(#_x_next_tile), a
;if (doChanege)
	ldh	a, (#_doChanege)
	or	a, a
	jr	Z, inc119$
;*chanegesPtr++ = iterX;
	ldh	a, (#_chanegesPtr)
	ld	c, a
	ld	b, #0xc2
	ldh	a, (#_iterX)
	ld	(bc), a
;*chanegesPtr++ = iterY;
	inc c
	ldh	a, (#_iterY)
	ld	(bc), a
	ld	a, c
	inc a
	ldh	(#_chanegesPtr), a
;continue;
	jr	inc119$
inc117$:
;function function = functions_map[*mapPtr];
	ld	h, #0x00
	ld	l, a
	add	hl, hl
	ld	bc, #_functions_map
	add	hl, bc
	ld	a, (hl+)
	ld	h, (hl)
	ld	l, a
;if (function != NULL)
	or	a, h
	jr	Z, inc119$
;function();
	rst	0x20
;if (doChanege)
	ldh	a, (#_doChanege)
	or	a, a
	jr	Z, inc119$
;*chanegesPtr++ = iterX;
	ldh	a, (#_chanegesPtr)
	ld	c, a
	ld	b, #0xc2
	ldh	a, (#_iterX)
	ld	(bc), a
;*chanegesPtr++ = iterY;
	inc c
	ldh	a, (#_iterY)
	ld	(bc), a
	ld	a, c
	inc a
	ldh	(#_chanegesPtr), a
inc119$:
;for (iterX = 0; iterX < 16; iterX++)
	ldh	a, (#_iterX)
	inc	a
	ldh	(#_iterX), a
	sub	a, #0x10
	jp	C, inc122$
;for (iterY = changeYstart; iterY < changeYend; iterY++)
	ldh	a, (#_iterY)
	inc	a
	ldh	(#_iterY), a
	jp	inc124$
inc121$:
;*chanegesPtr = 0xff;
	ldh	a, (#_chanegesPtr)
	ld	l, a
	ld	h, #0xc2
	ld	(hl), #0xff
	ret