/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
#include "pcbc.h"

static uint8_t *tmp = NULL;

size_t pcbc(blockcipher_fn cipher, uint8_t direction,
  uint8_t *in,
  uint8_t *out,
  uint8_t *iv,
  uint8_t *key,
  size_t key_size,
  size_t block_size,
  size_t length,
  uint8_t last) {

  size_t res = block_size;

  uint8_t in_xd[block_size];

  if (tmp == NULL) { 
    // first block, create tmp buffer
    tmp = malloc(block_size);
    memcpy(tmp, iv, block_size);
  }

  if (direction == ENCRYPT) {

    bc_xor(in, tmp, in_xd, block_size);
  }

  (*cipher)(direction, direction == ENCRYPT ? in_xd : in, out, key, key_size);
 
  if (direction == ENCRYPT) {
    bc_xor(in, out, tmp, block_size);
  }

  if (direction == DECRYPT) {
 
    bc_xor(out, tmp, out, block_size);
    bc_xor(in, out, tmp, block_size);
  }

  if (last) {
    free(tmp);
    tmp = NULL;
  }

  return res;
}
