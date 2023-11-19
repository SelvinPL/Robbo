.title  "PLATFORM"
.module platform
.area   _HEADER_CUSTOM_VBL_INT (ABS)
.globl	.vbl_done_alt

.org    0x40            ; VBL - no need for fancy GBDK one
.int_VBL:
    push af
    ld a, #1
    ldh (.vbl_done_alt), a
    pop af
    reti

.area _CODE
_wait_vbl_done_alt::
    xor a
    ldh (.vbl_done_alt), a
wait$:
    halt
    ldh a, (.vbl_done_alt)
    or a
    jr z, wait$
    ret

.area   _HRAM (ABS)
.org 0xffc0
.vbl_done_alt:
    .ds 1