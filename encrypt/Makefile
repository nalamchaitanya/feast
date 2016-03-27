# Makefile
#

SH = bash
CFLAGS = -c -g
LDFLAGS = -lm

all: encrypt decrypt

encrypt: Feast.o Encrypt.o
	gcc $(LDFLAGS) $^ -o $@

decrypt: Decrypt.o Encrypt.o
	gcc $(LDFLAGS) $^ -o $@

Encrypt.o: Encrypt.c Encrypt.h
	gcc $(CFLAGS) $< -o $@



.PHONY: clean

clean:
	rm *.o
