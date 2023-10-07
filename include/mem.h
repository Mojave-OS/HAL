#ifndef _HAL_MEMORY_H
#define _HAL_MEMORY_H

// This is the content for the memory access parts of the HAL. 
//
// Description: 
//  Although memory access seems trivial, we want to provide
//  a set of functions that can be used to perform memory
//  manipulation based on the premise that device drivers should
//  only perform memory access to interface with hardware peripherals
//  like GPIO though memory registers, therefore, this header file 
//  provides the blueprint for a set of functions and structs which
//  help abstract from the user some of the underlying complexities
//  of memory register operations.

/**
 * Memory Related Macro(s)
 */

/**
 * Memory Related Struct(s)
 */

// Memory Register Structure
typedef struct memory_register {
    unsigned int base;
    unsigned int offset;
    unsigned int membuf;
} memreg_t;

/**
 * Memory Related Method(s)
 */

// writes a memreg to the provided physical address
void mem_regw(memreg_t *m);

// reads a memreg from the provided pa, and write it 
// to the pointer target m.
void mem_regr(memreg_t *m);

#endif
