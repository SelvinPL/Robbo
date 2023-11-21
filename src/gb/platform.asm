.title  "PLATFORM"
.module platform
.area   _HEADER_CUSTOM_VBL_INT (ABS)
.vbl_done = 0xFF91          ; address of .vbl_done which is not exposed

.org    0x40            ; VBL - no need for fancy GBDK one
.int_VBL:
    push af
    ld a, #1
    ldh (.vbl_done), a
    pop af
    reti

.area _CODE
_wait_vbl_done_alt::
    xor a
    ldh (.vbl_done), a
wait$:
    halt
    ldh a, (.vbl_done)
    or a
    jr z, wait$
    ret