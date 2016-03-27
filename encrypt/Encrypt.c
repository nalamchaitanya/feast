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
    keys_arr = {1,2,3,4,5,6};
}


void global_variables()
{
    int i,j;
    char temp;

    sbox_arr        = (int *)malloc(64*sizeof(int));
    expansion_arr   = (int *)malloc(24*sizeof(int));
    diffusion_arr   = (int *)malloc(16*sizeof(int));

    expansion_arr = {15,9,13,10,4,12,6,7,6,16,15,14,8,7,5,11,1,2,5,13,1,9,4,3};
    diffusion_arr = {2,8,11,13,3,5,10,16,4,6,9,15,1,7,12,14};
    sbox_arr      = {14,0,4,15,13,7,1,4,2,14,15,2,11,13,8,1,3,10,10,6,6,12,12,11,5,9,9,5,0,3,7,8,4,15,1,12,14,8,8,2,13,4,6,9,2,1,11,7,15,5,12,11,9,3,7,14,3,10,10,0,5,6,0,13};

    return;
}

void fiestel(int input)
{
    int left,right,temp;
    int out_left,out_right,output;

    temp = 0xFFFF0000;
    left = input && temp;

    temp = 0x0000FFFF;
    right = input && temp;

    for(i=0;i<NO_OF_ROUNDS;i++)
    {
        out_left = right;
        temp = function(right,i);
        out_right = left^temp;
        left = out_left;
        right = out_right;
    }

    output = out_left+out_right;
    return;
}

int function(int input,int round_no)
{
    int temp;

    int expanded_input = 0;
    for(i=0;i<24;i++)
    {
        temp = input && onehot(15 - expansion_arr[i])
        if(temp!=0)
            expanded_input += onehot(23-i); 
    }

    xored_input = expanded_input ^ keys_arr[round_no];

    int sbox_input = 0;
    for(i=0;i<4;i++)
    {
        
        array[i] = input && onehot(31-i);
    }

    int diffused_input = 0;
    for(i=0;i<24;i++)
    {
        temp = input && onehot(15 - expansion_arr[i])
        if(temp!=0)
            diffused_input += onehot(15-i); 
    }
}