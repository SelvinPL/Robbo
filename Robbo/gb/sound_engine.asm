		.title  "SOUND ENGINE ASM"
		.module sound_engine_asm

		.area _CODE

		rAUD1SWEEP      = 0xFF10
		rAUD1LEN        = 0xFF11
		rAUD1ENV        = 0xFF12
		rAUD1LOW        = 0xFF13
		rAUD1HIGH       = 0xFF14

		rAUD2LEN        = 0xFF16
		rAUD2ENV        = 0xFF17
		rAUD2LOW        = 0xFF18
		rAUD2HIGH       = 0xFF19

		rAUD3ENA        = 0xFF1A
		rAUD3LEN        = 0xFF1B
		rAUD3LEVEL      = 0xFF1C
		rAUD3LOW        = 0xFF1D
		rAUD3HIGH       = 0xFF1E

		rAUD4LEN        = 0xFF20
		rAUD4ENV        = 0xFF21
		rAUD4POLY       = 0xFF22
		rAUD4GO         = 0xFF23
		
		rTAC            = 0xFF07

		PLAY			= 0x01
		MUTE			= 0x02
		WAIT			= 0x03
		STOP			= 0xff

		.globl	_soundState

_timerSoundProc::
;if (soundState.isPlaying & PLAY_CHANNEL1)
	ld		a,		(#_soundState + 0)
	ld		e,		a
	rrca
	jr		NC,		channel2$

;uint8_t* data = soundState.data[0];
	ld		bc,		#(_soundState + 1)
	ld		a,		(bc)
	ld		l,		a
	inc		bc
	ld		a,		(bc)
	ld		h,		a

;switch (*data++)
	ld		a,		(hl+)
	cp		a,		#PLAY
	jr		Z,		PLAY1$
	cp		a,		#MUTE
	jr		Z,		MUTE1$
	cp		a,		#WAIT
	jr		Z,		WAIT1$
	inc		a
	jr		Z,		STOP1$
	jr		channel2$

;case MUTE:
MUTE1$:
;rAUD1ENV = 0;
	xor		a,		a
	ldh		(rAUD1ENV), a
	jr		WAIT1$

;case STOP:
STOP1$:
;soundState.isPlaying ^= PLAY_CHANNEL1;
	ld		a,		e
	xor		a,		#1
	ld		e,		a
	ld		(#_soundState),	a
	jr		channel2$

;case PLAY:
PLAY1$:
;rAUD1SWEEP = *data++;
	ld		a,		(hl+)
	ldh		(rAUD1SWEEP),	a
;rAUD1LEN = *data++;
	ld		a,		(hl+)
	ldh		(rAUD1LEN),	a
;rAUD1ENV = *data++;
	ld		a,		(hl+)
	ldh		(rAUD1ENV),	a
;rAUD1LOW = *data++;
	ld		a,		(hl+)
	ldh		(rAUD1LOW),	a
;rAUD1HIGH = *data++;
	ld		a,		(hl+)
	ldh		(rAUD1HIGH),a

;case WAIT
WAIT1$:
;soundState.data[0] = data;
	ld		a,		h
	ld		(bc),	a
	dec		bc
	ld		a,		l
	ld		(bc),	a

channel2$:
;if (soundState.isPlaying & PLAY_CHANNEL2)
	bit		1,		e
	jr		Z,		channel3$
;uint8_t* data = soundState.data[1];
	ld		bc,		#(_soundState + 3)
	ld		a,		(bc)
	ld		l,		a
	inc		bc
	ld		a,		(bc)
	ld		h,		a

;switch (*data++)
	ld		a,		(hl+)
	cp		a,		#PLAY
	jr		Z,		PLAY2$
	cp		a,		#MUTE
	jr		Z,		MUTE2$
	cp		a,		#WAIT
	jr		Z,		WAIT2$
	inc		a
	jr		Z,		STOP2$
	jr		channel3$

;case MUTE:
MUTE2$:
;rAUD2ENV = 0;
	xor		a,		a
	ldh		(rAUD2ENV),	a
	jr		WAIT2$

;case STOP:
STOP2$:
;soundState.isPlaying ^= PLAY_CHANNEL2;
	ld		a,		e
	xor		a,		#2
	ld		e,		a
	ld		(#_soundState),	a
	jr		channel3$

;case PLAY:
PLAY2$:
;rAUD2LEN = *data++;
	ld		a,		(hl+)
	ldh		(rAUD2LEN),	a
;rAUD2ENV = *data++;
	ld		a,		(hl+)
	ldh		(rAUD2ENV),	a
;rAUD2LOW = *data++;
	ld		a,		(hl+)
	ldh		(rAUD2LOW),	a
;rAUD2HIGH = *data++;
	ld		a,		(hl+)
	ldh		(rAUD2HIGH),a

;case WAIT
WAIT2$:
;soundState.data[1] = data;
	ld		a,		h
	ld		(bc),	a
	dec		bc
	ld		a,		l
	ld		(bc),	a

channel3$:
;if (soundState.isPlaying & PLAY_CHANNEL3)
	bit		2,		e
	jr		Z,		channel4$
;uint8_t* data = soundState.data[2];
	ld		bc,		#(_soundState + 5)
	ld		a,		(bc)
	ld		l,		a
	inc		bc
	ld		a,		(bc)
	ld		h,		a

;switch (*data++)
	ld		a,		(hl+)
	cp		a,		#PLAY
	jr		Z,		PLAY3$
	cp		a,		#MUTE
	jr		Z,		MUTE3$
	cp		a,		#WAIT
	jr		Z,		WAIT3$
	inc		a
	jr		Z,		STOP3$
	jr		channel4$

;case MUTE:
MUTE3$:
;rAUD2ENV = 0;
	xor		a,		a
	ldh		(rAUD3ENA),	a
	jr		WAIT3$

;case STOP:
STOP3$:
;soundState.isPlaying ^= PLAY_CHANNEL3;
	ld		a,		e
	xor		a,		#4
	ld		e,		a
	ld		(#_soundState),a
	jr		channel4$

;case PLAY:
PLAY3$:
;rAUD3LEN = *data++;
	ld		a,		(hl+)
	ldh		(rAUD3LEN),	a
;rAUD3LEVEL = *data++;
	ld		a,		(hl+)
	ldh		(rAUD3LEVEL),a
;rAUD3LOW = *data++;
	ld		a,		(hl+)
	ldh		(rAUD3LOW), a
;rAUD3HIGH = *data++;
	ld		a,		(hl+)
	ldh		(rAUD3HIGH),a
;rAUD3ENA = 0x80;
	ld		a, #0x80
	ldh		(rAUD3ENA),	a

;case WAIT
WAIT3$:
;soundState.data[2] = data;
	ld		a,		h
	ld		(bc),	a
	dec		bc
	ld		a,		l
	ld		(bc),	a

channel4$:
;if (soundState.isPlaying & PLAY_CHANNEL4)
	bit		3,		e
	ret		Z
;uint8_t* data = soundState.data[3];
	ld		bc,		#(_soundState + 7)
	ld		a,		(bc)
	ld		l,		a
	inc		bc
	ld		a,		(bc)
	ld		h,		a

;switch (*data++)
	ld		a,		(hl+)
	cp		a,		#PLAY
	jr		Z,		PLAY4$
	cp		a,		#MUTE
	jr		Z,		MUTE4$
	cp		a,		#WAIT
	jr		Z,		WAIT4$
	inc		a
	jr		Z,		STOP4$
	ret

;case MUTE:
MUTE4$:
;rAUD4ENV = 0;
	xor		a,		a
	ldh		(rAUD4ENV),	a
	jr		WAIT4$

;case STOP:
STOP4$:
;soundState.isPlaying ^= PLAY_CHANNEL4;
	ld		a,		e
	xor		a,		#8
	ld		e,		a
	ld		(#_soundState),a
	ret

;case PLAY:
PLAY4$:
;rAUD4LEN = *data++;
	ld		a,		(hl+)
	ldh		(rAUD4LEN),	a
;rAUD4ENV = *data++;
	ld		a,		(hl+)
	ldh		(rAUD4ENV),	a
;rAUD4POLY = *data++;
	ld		a,		(hl+)
	ldh		(rAUD4POLY),a
;rAUD4GO = *data++;
	ld		a,		(hl+)
	ldh		(rAUD4GO),	a

;case WAIT
WAIT4$:
;soundState.data[3] = data;
	ld		a,		h
	ld		(bc),	a
	dec		bc
	ld		a,		l
	ld		(bc),	a
	ret