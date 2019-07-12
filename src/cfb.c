/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
#include "cfb.h"

static uint8_t *tmp = NULL;

size_t cfb(blockcipher_fn cipher, uint8_t direction,
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
    tmp = malloc(block_size);
    memcpy(tmp, iv, block_size);
  }

  // CFB cipher always encrypts
  (*cipher)(ENCRYPT, tmp, out, key, key_size);

  if (direction == ENCRYPT) {
    bc_xor(in, out, out, block_size);
    memcpy(tmp, out, block_size);
  }

  if (direction == DECRYPT) {
    memcpy(tmp, in, block_size);
    bc_xor(in, out, out, block_size);
  }

  if (last) {
    free(tmp);
    tmp = NULL;
  }

  return res;
}
