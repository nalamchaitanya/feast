#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// All #defines here.(rounds,keysize,etc.)
#define NO_OF_ROUNDS 6
#define KEY_SIZE     24
#define INPUT_SIZE   32

// Task 1: Create the substitution box as an array i.e if you give s1[64] it
// must give the substitution of it. Fill array with appropritate values. Use
// s1.m function in matlab to get elements in the order s1[0],s1[1]...

// Takes a key and gives round no of keys as an array.
// void keygen(int key);

// This is expand function which expands 16 bit to 24 bit.
int expand(short int half);

// This is for substitution of 24 bit to 16 bit.
short int subst(int sub);

// This is for permutation after substitution. rearrange bits to get a short int
short int perm(short int sub);

// This gives one hot at the given index.
int onehot(int index);

// This prints the int in form of bits.
void printbits(int num);


int fiestel(int input);
int function(int input,int round_no);

#endif
