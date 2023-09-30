#ifndef _HAL_MINI_UART_H
#define _HAL_MINI_UART_H

// This is the content for the mini uart parts of the HAL.
//
// Description
//  Mini-UART is used for communication and is provided by the 
//  BCM2711 as a memory mapped register. This header file provides
//  the interface that we'll use to abstract the mini uart hardware.

#include "mem.h"

/**
 * Mini Uart Related Struct(s)
 */

// Title: AUX_IRQ Register
// Description: Register used to see if the device has requested an
//              interrupt. 
typedef struct {
    unsigned char SPI_2_IRQ;
    unsigned char SPI_1_IRQ;
    unsigned char MINIU_IRQ;
} AUX_IRQ_REG;
void cnv_aux_irq_reg(AUX_IRQ_REG *a, memreg_t *m);

// Title: AUX_ENABLES Register
// Description: Register used to enable the specific AUX modules.
typedef struct  {
    unsigned char SPI_2_ENABLE;
    unsigned char SPI_1_ENABLE;
    unsigned char MINIU_ENABLE;
} AUX_ENABLES_REG;
void cnv_aux_enables_reg(AUX_ENABLES_REG *a, memreg_t *m);

// Title: AUX_MU_IO_REG Register
// Description: Register is used to primarily write/read data from the UART FIFOs.
//              Also used to read the LSB byte of the baud rate (easier way to 
//              do this).
typedef struct {
    unsigned char BAUDRATE_LSB;
    unsigned char TX; // requires that bit 7 of the line control reg (DLAB bit) is clear.
    unsigned char RX; // ^
} AUX_MU_IO_REG;
void cnv_aux_mu_io_reg(AUX_MU_IO_REG *a, memreg_t *m);

// Title: AUX_MU_IER_REG Register
// Description: Register is used to primarily enable interrupts. 
typedef struct {
    unsigned char BAUDRATE_MSB;
    unsigned char RX_INT_ENABLE; // seems to require that DLAB=0
    unsigned char TX_INT_ENABLE; // ^
} AUX_MU_IER_REG;
void cnv_aux_mu_ier_reg(AUX_MU_IER_REG *a, memreg_t *m);

#endif
