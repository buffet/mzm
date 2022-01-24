TARGET = mzm_us.gba
BASEROM = baserom_us.gba
SHA1FILE = mzm.sha1
ELF = $(TARGET:.gba=.elf)
MAP = $(TARGET:.gba=.map)
DUMPS = $(TARGET:.gba=.dump) $(BASEROM:.gba=.dump)

# ROM header
GAME_TITLE = ZEROMISSIONE
GAME_CODE= BMXE
MAKER_CODE = 01
GAME_REVISION = 00

# Binaries
TOOLCHAIN ?= arm-none-eabi-
AS = $(TOOLCHAIN)as
CC = ./tools/agbcc/agbcc
LD = $(TOOLCHAIN)ld
OBJCOPY = $(TOOLCHAIN)objcopy
OBJDUMP = $(TOOLCHAIN)objdump

DIFF = diff -u
HOSTCC = cc
RM = rm -f
SHA1SUM = sha1sum
TAIL = tail

GBAFIX = tools/gbafix/gbafix

# Flags
ASFLAGS = -mcpu=arm7tdmi
CCFLAGS = -O2 -mthumb-interwork

# Objects
ASM =                                                                        \
	asm/romheader.s                                                            \
	asm/crt0.s                                                                 \
	asm/intr_main.s                                                            \
	asm/blob_0x0000023c-0x000007d0.s                                           \
	asm/check_softreset.s                                                      \
	asm/blob_0x00000804-0x00000968.s                                           \
	asm/blob_0x000009a0-0x00005190.s                                           \
	asm/syscalls.s                                                             \
	asm/blob_0x000051d4-0x00800000.s

SRC =                                                                        \
  src/update_input.c

OBJ = $(ASM:.s=.o) $(SRC:.c=.o) $(BLOBS)

# Enable verbose output
ifeq ($(V),1)
	Q =
	MSG = @:
else
	Q = @
	MSG = @echo " "
endif


.PHONY: all
all: $(TARGET)

.PHONY: check
check: all
	$(MSG) SHA1SUM $(SHA1FILE)
	$Q$(SHA1SUM) -c $(SHA1FILE)

.PHONY: dump
dump: $(DUMPS)

.PHONY: diff
diff: $(DUMPS)
	$(MSG) DIFF $^
	$Q$(DIFF) $^

.PHONY: clean
clean:
	$(MSG) RM $(TARGET)
	$Q$(RM) $(TARGET) $(ELF) $(MAP)
	$(MSG) RM $(DUMPS)
	$Q$(RM) $(DUMPS)
	$(MSG) RM $(OBJ)
	$Q$(RM) $(OBJ)
	$(MSG) RM $(GBAFIX)
	$Q$(RM) $(GBAFIX)

.PHONY: help
help:
	@echo 'Targets:'
	@echo '  all: build the ROM'
	@echo '  check: checksum the ROM'
	@echo '  dump: dump the ROMs'
	@echo '  diff: compare the ROM with the original'
	@echo '  clean: remove the ROM and intermediate files'
	@echo '  help: show this message'
	@echo ''
	@echo 'Flags:'
	@echo '  V=1: enable verbose output'


$(TARGET): $(ELF) $(GBAFIX)
	$(MSG) OBJCOPY $@
	$Q$(OBJCOPY) -O binary --gap-fill 0xff --pad-to 0x08800000 $< $@
	$(MSG) GBAFIX $@
	$Q$(GBAFIX) $@ -t$(GAME_TITLE) -c$(GAME_CODE) -m$(MAKER_CODE) -r$(GAME_REVISION)

$(ELF) $(MAP): $(OBJ) linker.ld
	$(MSG) LD $@
	$Q$(LD) $(LDFLAGS) -n -T linker.ld -Map=$(MAP) -o $@ $(OBJ)

%.dump: %.gba
	$(MSG) OBJDUMP $@
	$Q$(OBJDUMP) -D -bbinary -marm7tdmi -Mforce-thumb $< | $(TAIL) -n+3 > $@

%.o: %.s
	$(MSG) AS $@
	$Q$(AS) $(ASFLAGS) $< -o $@

%.s: %.c
	$(MSG) CC $@
	$Q$(CC) $(CCFLAGS) $< -o $@

tools/%: tools/%.c
	$(MSG) HOSTCC $@
	$Q$(HOSTCC) $< $(CFLAGS) $(CPPFLAGS) -o $@
