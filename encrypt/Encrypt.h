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
int *keys_arr;
int **sbox_arr;
int *expansion_arr;
int *diffusion_arr;

// This is permutation choice 1 for the key generation.
int pc1left[2][7] = {{25,17,9,1,26,18,10},{2,27,19,11,3,12,28}};
int pc1right[2][7] = {{31,23,15,7,30,22,14},{6,29,21,13,5,20,4}};

// This is permutation choice 2 for the key generation.
int pc2[24] = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2};

// Shift array in each round.
int shift[ROUNDS] = {1,2,2,1,2,1};

// Takes a key and gives round no of keys as an array.
int* keygen(int key);

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


void fileread();
void fiestel(int input);
int function(int input,int round_no);

#endif
