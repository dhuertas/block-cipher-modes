/*
 * Block Cipher Modes of Operation
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 */
#ifndef __MAIN_H__
#define __MAIN_H__

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FALSE 0
#define TRUE 1

#define BUFFER_SIZE 128

#define MAX_KEY_SIZE 32
#define MAX_IV_SIZE 32

typedef struct {
  char *cipher;
  uint8_t direction;
  char *key;
  char *iv;
  char *mode;
  char *read_file;
  char *write_file;
  uint8_t verbose;
} options_t;

#endif
