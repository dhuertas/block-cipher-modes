/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
#ifndef __BLOCKCIPHER_H__
#define __BLOCKCIPHER_H__

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 16

#define ENCRYPT 0
#define DECRYPT 1

typedef void (*blockcipher_fn)(uint8_t direction, uint8_t *in, uint8_t *out, uint8_t *key, size_t key_size);

typedef size_t (*blockcipher_mode_fn)(blockcipher_fn cipher, uint8_t direction,
  uint8_t *in, 
  uint8_t *out, 
  uint8_t *iv,
  uint8_t *key, 
  size_t key_size,
  size_t block_size, 
  size_t length, 
  uint8_t last);

typedef struct {
  char *name;
  uint32_t block_size;
  blockcipher_fn func; 
} blockcipher_t;

typedef struct {
  char *name;
  uint8_t iv;
  blockcipher_mode_fn func;
} blockcipher_mode_t;

size_t bc_get_block_size(char *cipher, blockcipher_t *list);

blockcipher_t *bc_get_blockcipher(char *cipher, blockcipher_t *list);

blockcipher_mode_t *bc_get_mode(char *name, blockcipher_mode_t *list);

void bc_add_padding(uint8_t *buffer, size_t block_size, size_t length);

size_t bc_remove_padding(uint8_t *buffer, size_t block_size, size_t length);

void bc_xor(uint8_t *a, uint8_t *b, uint8_t *res, size_t block_size);

#endif
