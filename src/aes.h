/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
/*
 * Advanced Encryption Standard
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 * @repo https://github.com/dhuertas/AES
 *
 * Based on the document FIPS PUB 197
 */
#ifndef __AES_H__
#define __AES_H__

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Multiplication in GF(2^8) using a lookup table
 * http://en.wikipedia.org/wiki/Finite_field_arithmetic
 * Irreducible polynomial m(x) = x8 + x4 + x3 + x + 1
 */
#define gmult(a, b) gmult_aes[256*a + b]

uint8_t *aes_init(size_t key_size);

void aes_key_expansion(uint8_t *key, uint8_t *w);

void aes_inv_cipher(uint8_t *in, uint8_t *out, uint8_t *w);

void aes_cipher(uint8_t *in, uint8_t *out, uint8_t *w);

void aes(uint8_t direction, uint8_t *in, uint8_t *out, uint8_t *key, size_t key_size);

#endif
