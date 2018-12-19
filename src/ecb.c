/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
#include <stdio.h>
#include "ecb.h"

size_t ecb(blockcipher_fn cipher, uint8_t direction, 
  uint8_t *in, 
  uint8_t *out, 
  uint8_t *iv,
  uint8_t *key, 
  size_t key_size,
  size_t block_size, 
  size_t length, 
  uint8_t last) {

  size_t res = block_size;

  (*cipher)(direction, in, out, key, key_size);

  return res;
}
