# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
GBDK_HOME	=c:/gb/gbdk/
LCC			=$(GBDK_HOME)bin/lcc
PNG2ASSET	=$(GBDK_HOME)bin/png2asset

# You can set the name of the ROM file here
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))

PROJECTNAME = $(current_dir)

# Set platforms to build here, spaced separated. (These are in the separate Makefile.targets)
# They can also be built/cleaned individually: "make gg" and "make gg-clean"
# Possible are: gb gbc pocket megaduck sms gg
TARGETS=gbc sms


MAP_TO_TILES0_HI	=0xC2
MAP_TO_TILES0_LO	=0x00
MAP_TO_TILES0		=$(MAP_TO_TILES0_HI)$(subst 0x,,$(MAP_TO_TILES0_LO))
MAP_TO_TILES1_HI	=0xC2
MAP_TO_TILES1_LO	=0x80
MAP_TO_TILES1		=$(MAP_TO_TILES1_HI)$(subst 0x,,$(MAP_TO_TILES1_LO))
MAP_TO_TILES2_HI	=0xC3
MAP_TO_TILES2_LO	=0x00
MAP_TO_TILES2		=$(MAP_TO_TILES2_HI)$(subst 0x,,$(MAP_TO_TILES2_LO))
MAP_TO_TILES3_HI	=0xC3
MAP_TO_TILES3_LO	=0x80
MAP_TO_TILES3		=$(MAP_TO_TILES3_HI)$(subst 0x,,$(MAP_TO_TILES3_LO))

MAP_TO_TILES			 = -Wf-DMAP_TO_TILES0_HI=$(MAP_TO_TILES0_HI) -Wf-DMAP_TO_TILES0_LO=$(MAP_TO_TILES0_LO)
MAP_TO_TILES_LINKER		 = -Wl-g_map_to_tiles0=$(MAP_TO_TILES0)
MAP_TO_TILES			+= -Wf-DMAP_TO_TILES1_HI=$(MAP_TO_TILES1_HI) -Wf-DMAP_TO_TILES1_LO=$(MAP_TO_TILES1_LO)
MAP_TO_TILES_LINKER		+= -Wl-g_map_to_tiles1=$(MAP_TO_TILES1)
MAP_TO_TILES			+= -Wf-DMAP_TO_TILES2_HI=$(MAP_TO_TILES2_HI) -Wf-DMAP_TO_TILES2_LO=$(MAP_TO_TILES2_LO)
MAP_TO_TILES_LINKER		+= -Wl-g_map_to_tiles2=$(MAP_TO_TILES2)
MAP_TO_TILES			+= -Wf-DMAP_TO_TILES3_HI=$(MAP_TO_TILES3_HI) -Wf-DMAP_TO_TILES3_LO=$(MAP_TO_TILES3_LO)
MAP_TO_TILES_LINKER		+= -Wl-g_map_to_tiles3=$(MAP_TO_TILES3)

LOCATIONS		 =-Wl-g_map=0xC000

LOCATIONS		+=-Wl-g_changes=0xC400

LOCATIONS		+=$(MAP_TO_TILES_LINKER)

DATA_LOCATION	 =0xC4D0
#free RAM start
LOCATIONS		+=-Wl-b_DATA=$(DATA_LOCATION)

ASM_CODE		=-Wf-DSET_BKG_TILE_ASM

NINTEND_SEGA_LINKER	=$(LOCATIONS) -Wl-g_shadow_OAM=0x0000 -autobank
NINTENDO_FLAGS	=$(NINTEND_SEGA_LINKER) -Wl-g.refresh_OAM=0xff80 -Wl-yt0x1B
SEGA_FLAGS		=$(NINTEND_SEGA_LINKER)
# Configure platform specific LCC flags here:
LCCFLAGS_gb		=$(NINTENDO_FLAGS) # Set an MBC for banking (1B-ROM+MBC5+RAM+BATT)
LCCFLAGS_pocket	=$(NINTENDO_FLAGS) # Usually the same as required for .gb
LCCFLAGS_duck	=$(NINTENDO_FLAGS) # Usually the same as required for .gb
LCCFLAGS_gbc	=$(NINTENDO_FLAGS) -Wm-yc # Same as .gb with: -Wm-yc (gb & gbc) or Wm-yC (gbc exclusive)
LCCFLAGS_sms	=$(SEGA_FLAGS)
LCCFLAGS_gg		=$(SEGA_FLAGS)
LCCFLAGS_nes	=-autobank

LCCFLAGS		+= $(LCCFLAGS_$(EXT)) # This adds the current platform specific LCC Flags

LCCFLAGS		+= -Wl-j -Wm-yoA -Wm-ya4 -Wb-ext=.rel -Wb-v # MBC + Autobanking related flags
#LCCFLAGS += -debug # Uncomment to enable debug output
#LCCFLAGS += -v     # Uncomment for lcc verbose output

P2AFLAGS_gb		= -map -bpp 2 -max_palettes 4 -pack_mode gb -noflip
P2AFLAGS_gbc	= -map -use_map_attributes -bpp 2 -max_palettes 8 -pack_mode gb
P2AFLAGS_pocket	= -map -bpp 2 -max_palettes 4 -pack_mode gb -noflip
P2AFLAGS_duck	= -map -bpp 2 -max_palettes 4 -pack_mode gb -noflip
P2AFLAGS_sms	= -map -use_map_attributes -bpp 4 -max_palettes 2 -pack_mode sms
P2AFLAGS_gg		= -map -use_map_attributes -bpp 4 -max_palettes 2 -pack_mode sms
P2AFLAGS_nes	= -map -bpp 2 -max_palettes 4 -pack_mode nes -noflip -use_nes_attributes -b 0

P2AFLAGS		= $(P2AFLAGS_$(EXT))

CFLAGS			= -Wf-MMD -Wf--disable-warning=283 -Wf--disable-warning=110 -Wf"--data-loc $(DATA_LOCATION)" $(MAP_TO_TILES) $(ASM_CODE)

# EXT?=gb # Only sets extension to default (game boy .gb) if not populated
SRCDIR      = src
OBJDIR      = obj/$(EXT)
RESOBJSRC   = obj/$(EXT)/res
RESDIR      = res
BINDIR      = build/$(EXT)
PLATDIR		= $(SRCDIR)/$(PLAT)
MKDIRS      = $(OBJDIR) $(BINDIR) $(RESOBJSRC) $(PLATOBJDIR) # See bottom of Makefile for directory auto-creation
ifneq ($(strip $(COMMON)),)
COMMONDIR		= $(SRCDIR)/$(COMMON)
COMMONINCLUDE	= -Iinclue/$(COMMON)
endif

BINS	        = $(OBJDIR)/$(PROJECTNAME).$(EXT)
CSOURCES        = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c)))
CPLATSOURCES    = $(foreach dir,$(PLATDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES      = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.asm)))
ASMPLATSOURCES  = $(foreach dir,$(PLATDIR),$(notdir $(wildcard $(dir)/*.asm)))
OBJS        	= $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.asm=$(OBJDIR)/%.o) $(CPLATSOURCES:%.c=$(OBJDIR)/$(PLAT)_%.o) $(ASMPLATSOURCES:%.asm=$(OBJDIR)/$(PLAT)_%.o)
ifneq ($(strip $(COMMON)),)
COMMONDIR   = $(SRCDIR)/$(COMMON)
CCOMMONSOURCES  = $(foreach dir,$(COMMONDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMCOMMONSOURCES = $(foreach dir,$(COMMONDIR),$(notdir $(wildcard $(dir)/*.asm)))
OBJS +=  $(CCOMMONSOURCES:%.c=$(OBJDIR)/$(COMMON)_%.o) $(ASMCOMMONSOURCES:%.asm=$(OBJDIR)/$(COMMON)_%.o)
endif

# For png2asset: converting map source pngs -> .c -> .o
MAPPNGS		= $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.png)))
MAPSRCS		= $(MAPPNGS:%.png=$(RESOBJSRC)/%.c)
MAPOBJS		= $(MAPSRCS:$(RESOBJSRC)/%.c=$(OBJDIR)/%.o)

.PRECIOUS: $(MAPSRCS)

CFLAGS += -I$(OBJDIR) -Wa-l -Iinclude

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS	+= -Wl-y -debug -Wf--peep-asm -Wf--peep-return -Wf"--peep-file $(COMMONDIR)/peep.txt"
else
    CFLAGS	+= -Wf--peep-asm -Wf--peep-return -Wf--opt-code-speed -Wf"--max-allocs-per-node 600000" -Wf"--peep-file $(COMMONDIR)/peep.txt"
endif

# Builds all targets sequentially
all: $(TARGETS)

# Use png2asset to convert the png into C formatted map data
# -c ...   : Set C output file
# Convert metasprite .pngs in res/ -> .c files in obj/<platform ext>/src/
$(RESOBJSRC)/%.c:	$(RESDIR)/%.png
	$(PNG2ASSET) $< $(P2AFLAGS) -c $@

# Compile the map pngs that were converted to .c files
# .c files in obj/<platform ext>/src/ -> .o files in obj/
$(OBJDIR)/%.o:	$(RESOBJSRC)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Dependencies
DEPS = $(OBJS:%.o=%.d)

-include $(DEPS)

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .c files in "src/PLAT/" to .o object files
$(OBJDIR)/$(PLAT)_%.o:	$(PLATDIR)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .c files in "src/COMMON/" to .o object files
$(OBJDIR)/$(COMMON)_%.o:	$(COMMONDIR)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.asm
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/PLAT/" to .o object files
$(OBJDIR)/$(PLAT)_%.o:	$(PLATDIR)/%.asm
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/COMMON/" to .o object files
$(OBJDIR)/$(COMMON)_%.o:	$(COMMONDIR)/%.asm
	$(LCC) $(CFLAGS) -c -o $@ $<

# If needed, compile .c files in "src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(CFLAGS) -S -o $@ $<

# Convert and build maps first so they're available when compiling the main sources
$(OBJS):	$(MAPOBJS)

# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS)
	$(LCC) $(LCCFLAGS) $(CFLAGS) -o $(BINDIR)/$(PROJECTNAME).$(EXT) $(MAPOBJS) $(OBJS)

clean:
	@echo Cleaning
	@for target in $(TARGETS); do \
		$(MAKE) $$target-clean; \
	done

# Include available build targets
include Makefile.targets


# create necessary directories after Makefile is parsed but before build
# info prevents the command from being pasted into the makefile
ifneq ($(strip $(EXT)),)           # Only make the directories if EXT has been set by a target
$(info $(shell mkdir -p $(MKDIRS)))
endif
