/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
#include <string.h>

#include "block-cipher.h"

//------------------------------------------------------------------------------
blockcipher_t *bc_get_blockcipher(char *cipher, blockcipher_t *list) {

  size_t i = 0;

  while (list[i].name != NULL) {

    if (strcmp(cipher, list[i].name) == 0) { 
      return &list[i];
    }

    i++;
  }

  return NULL;
}

//------------------------------------------------------------------------------
blockcipher_fn bc_get_func(char *cipher, blockcipher_t *list) {

  unsigned int i = 0;

  while (list[i].name != NULL) {

    if (strcmp(cipher, list[i].name) == 0) { 
      return list[i].func;
    }

    i++;
  }

  return NULL;
}

//------------------------------------------------------------------------------
blockcipher_mode_t *bc_get_mode(char *name, blockcipher_mode_t *list) {

  unsigned int i = 0;

  while (list[i].name != NULL) {

    if (strcmp(name, list[i].name) == 0) {
      return &list[i];
    }

    i++;
  }

  return NULL;
}

//------------------------------------------------------------------------------
void bc_add_padding(uint8_t *buffer, size_t block_size, size_t length) {

  uint8_t padding_byte = (uint8_t )(length == block_size ? block_size : block_size - length);

  uint8_t tmp_buffer[block_size];

  if (length == block_size) {
    memset(buffer, padding_byte, block_size);
  } else {
    memset(tmp_buffer, padding_byte, block_size);
    memcpy(tmp_buffer, buffer, length);
    memcpy(buffer, tmp_buffer, block_size);
  }
}

//------------------------------------------------------------------------------
size_t bc_remove_padding(uint8_t *buffer, size_t block_size, size_t length) {

  uint8_t padding_value = buffer[length-1];

  if (padding_value > block_size) {
    // Most likely decryption failed
    return 0;
  }

  size_t padding_length = 0;

  uint8_t count = padding_value;

  while (count) {

    count--;
    padding_length++;
  }

  return block_size >= padding_length ? block_size - padding_length : 0;
}

//------------------------------------------------------------------------------
void bc_xor(uint8_t *a, uint8_t *b, uint8_t *res, size_t block_size) {

  uint8_t i = 0;
  for ( ; i < block_size; i++) {
    res[i] = a[i] ^ b[i];
  }
}
