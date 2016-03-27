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
int keys_arr[NO_OF_ROUNDS] = {1,2,3,4,5,6};
int expansion_arr[24] = {15,9,13,10,4,12,6,7,6,16,15,14,8,7,5,11,1,2,5,13,1,9,4,3};;
int diffusion_arr[16] = {2,8,11,13,3,5,10,16,4,6,9,15,1,7,12,14};
int sbox_arr[64]      = {14,0,4,15,13,7,1,4,2,14,15,2,11,13,8,1,3,10,10,6,6,12,12,11,5,9,9,5,0,3,7,8,4,15,1,12,14,8,8,2,13,4,6,9,2,1,11,7,15,5,12,11,9,3,7,14,3,10,10,0,5,6,0,13};

// Takes a key and gives round no of keys as an array.
void keygen(int key);

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


void fiestel(int input);
int function(int input,int round_no);

#endif
