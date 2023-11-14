.title  "PLATFORM"
.module platform
.area   _HEADER (ABS)

    .org    0x3F            ; VBL - no need for fancy GBDK one
.int_VBL:
    reti