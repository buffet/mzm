#include "funcs.h"
#include "gba.h"
#include "globals.h"
#include "memory.h"
#include "sram/sram.h"
#include "types.h"

void
sub_08000c04(void)
{
    bit_fill(3, 0xffff, &unk_02038000, SRAM_SIZE, 16);
    if (unk_03000c1c == 0) {
        sram_write_checked(unk_02038000, SRAM_BASE, SRAM_SIZE);
    }
}
