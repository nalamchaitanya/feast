#ifndef ENCRYPT_H
#define ENCRYPT_H

// All #defines here.(rounds,keysize,etc.)

// Task 1: Create the substitution box as an array i.e if you give s1[64] it
// must give the substitution of it. Fill array with appropritate values. Use
// s1.m function in matlab to get elements in the order s1[0],s1[1]...

int s1[64] = {0,0,0};

// This is the expansion array which is in the exp.csv
int exp[24] = {0,0,0};

// This is the permutation array which is in the diffu.csv
int dif[24] = {0,0,0};

// Takes a key and gives round no of keys as an array.
int* keygen(int key);

// This is expand function which expands 16 bit to 24 bit.
int expand(short int half);

// This is for substitution of 24 bit to 16 bit.
short int subst(int sub);

// This is for permutation after substitution. rearrange bits to get a short int
short int perm(short int sub);

#endif
