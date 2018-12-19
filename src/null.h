/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
#ifndef __NULL_H__
#define __NULL_H__

#include <stdint.h>

void null(uint8_t direction, uint8_t *in, uint8_t *out, uint8_t *key, size_t key_size);

#endif
