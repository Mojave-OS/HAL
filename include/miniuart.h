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

// Title: AUX_MU_IIR_REG Register
// Description: Register is used to show the interupt status, and a bit range for 
//              clearing the RX/TX FIFO.
typedef struct {
    unsigned char FIFO_ENABLED; // always reads 1 according to documentation
    unsigned char ZERO; // always reads zero
    unsigned char INT_ID;
    unsigned char FIFO_CLEAR;
    unsigned char INT_PENDING; 
} AUX_MU_IIR_REG;

// Title: AUX_MU_LCR_REG Register
// Description: Register controls the line data format and gives access to the
//              baudrate register.
typedef struct {
    unsigned char DLAB_ENABLED;
    unsigned char BREAK; // If set the UART1_TX line will be pulled low continuously.
    unsigned char DATA_SIZE; // if set, uart = 8 bit mode, else 7.
} AUX_MU_LCR_REG;


// Title: AUX_MU_MCR_REG Register
// Description: Register controls the "modem" signals. 
typedef struct {
    unsigned char RTS;
} AUX_MU_MCR_REG;

// Title: AUX_MU_LSR_REG Register
// Description: Register shows the data status.
typedef struct {
    unsigned char TRANSMITTER_IDLE;
    unsigned char TRANSMITTER_EMPTY;
    unsigned char RECV_OVERRUN;
    unsigned char DATA_READY;
} AUX_MU_LSR_REG;

// Title: AUX_MU_MSR_REG Register
// Description: Register shows the "modem" status.
typedef struct {
    unsigned char CTS_STATUS;
} AUX_MU_MSR_REG;


// Title: AUX_MU_SCRATCH Register
// Description: Register provides a single byte of temporary storage.
typedef struct {
    unsigned char SCRATCH;
} AUX_MU_SCRATCH_REG;

// Title: AUX_MU_CNTL_REG Register
// Description: Register provides access to some really nice features not found
//              in the normal 16550 UART.
typedef struct {
    unsigned char CTS_ASSERT_LEVEL;
    unsigned char RTS_ASSERT_LEVEL;
    unsigned char RTS_AUTO_FLOW_LEVEL;
    unsigned char TX_AUTO_FLOW_CNTRL_CTS_ENABLE;
    unsigned char RX_AUTO_FLOW_CNTRL_RTS_ENABLE;
    unsigned char TX_ENABLE;
    unsigned char RX_ENABLE;
} AUX_MU_CNTL_REG;

// Title: AUX_MU_STAT_REG Register
// Description: Register provides useful internal status of the mini UART.
typedef struct {

} AUX_MU_STAT_REG;

// Title: AUX_MU_BAUD_REG Register
// Description: Allows direct access to the 16bit wide baudrate counter.
typedef struct {
    unsigned char BAUDRATE;
} AUX_MU_BAUD_REG;

#endif
