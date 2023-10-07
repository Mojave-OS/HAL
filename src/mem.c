#include "mem.h"

void mem_regw(memreg_t *m) {
    *(volatile unsigned int *)(m->base + m->offset * 0x8) = m->membuf;
}

void mem_regr(memreg_t *m) {
    volatile unsigned int membuf = *(volatile unsigned int *)(m->base + m->offset * 0x8);
    m->membuf = membuf;
}
