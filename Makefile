#
# Block Cipher Modes of Operation
# @author Dani Huertas
# @email huertas.dani@gmail.com
#
CC = gcc
CFLAGS = -Wall
SHELL = /bin/bash

TARGET = bcm

LIBS =

INCLUDE = -I./src

SOURCES = $(shell find ./src -type f -name '*.c' )

OBJS = $(shell find ./src -type f -name '*.c' | sed -e 's/\.c/\.o/g' -e 's/src\//obj\//g')

all: debug

debug: CFLAGS += -g
debug: $(TARGET)

release: CFLAGS += -O2
release: $(TARGET)

depend: _depend

_depend: $(SOURCES)
	rm -f ./.depend
	$(CC) $(CFLAGS) $(INCLUDE) -MM $^ > ./.depend;

obj/%.o: src/%.c
	@mkdir -m 755 -p $$(dirname $@)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

clean:
	@rm -f .depend
	@rm -rf obj
	@rm -rf out
	@rm -rf ./*.out
	@rm -f $(TARGET)
