#include "Encrypt.h"

// Implement all the functions here.

// This gives one hot at the given index.
int onehot(int index)
{
    return (int)pow(2,index);
}

// This prints the int in form of bits.
void printbits(int num)
{
    int i;
    i = 31;
    int p = (int)pow(2,31);
    printf("<--");
    while(i>=0)
    {
        printf("%d",num/p);
        num = num<<1;
        i--;
    }
    printf("-->\n");
}

// Takes a key and gives round no of keys as an array.
int* keygen(int key)
{
    int *keys = (int*)malloc(sizeof(int)*ROUNDS);
    int i = 0;
    char l1,l2,r1,r2;
    while(i<ROUNDS)
    {
        // TODO key schedule.
    }
}
