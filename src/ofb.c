/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
#include "ofb.h"

static uint8_t *tmp = NULL;

size_t ofb(blockcipher_fn cipher, uint8_t direction,
  uint8_t *in,
  uint8_t *out,
  uint8_t *iv,
  uint8_t *key,
  size_t key_size,
  size_t block_size,
  size_t length,
  uint8_t last) {

  size_t res = block_size;

  if (tmp == NULL) { 
    // first call, create tmp buffer and set to IV
    tmp = malloc(block_size);
    memcpy(tmp, iv, block_size);
  }

  (*cipher)(ENCRYPT, tmp, out, key, key_size);

  memcpy(tmp, out, block_size);

  bc_xor(out, in, out, block_size);

  if (last) {
    free(tmp);
    tmp = NULL;
  }

  return res;
}
