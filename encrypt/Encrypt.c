#include "Encrypt.h"

// Implement all the functions here.
int keys_arr[NO_OF_ROUNDS] = {1,2,3,4,5,6};
int expansion_arr[24] = {15,9,13,10,4,12,6,7,6,16,15,14,8,7,5,11,1,2,5,13,1,9,4,3};;
int diffusion_arr[16] = {2,8,11,13,3,5,10,16,4,6,9,15,1,7,12,14};
int sbox_arr[64]      = {14,0,4,15,13,7,1,4,2,14,15,2,11,13,8,1,3,10,10,6,6,12,12,11,5,9,9,5,0,3,7,8,4,15,1,12,14,8,8,2,13,4,6,9,2,1,11,7,15,5,12,11,9,3,7,14,3,10,10,0,5,6,0,13};

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


void fiestel(int input)
{
    int i;
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
    int temp,temp1,i;

    int expanded_input = 0;
    for(i=0;i<24;i++)
    {
        temp = input && onehot(15 - expansion_arr[i]);
        if(temp!=0)
            expanded_input += onehot(23-i);
    }

    int xored_input = expanded_input ^ keys_arr[round_no];

    int sbox_input = 0;
    for(i=0;i<4;i++)
    {
        temp = 0X000000FF;
        temp1 = xored_input && temp;
        sbox_input += sbox_arr[temp1] * onehot(8*i);
        xored_input >> 8;
    }

    int diffused_input = 0;
    for(i=0;i<24;i++)
    {
        temp = input && onehot(15 - expansion_arr[i]);
        if(temp!=0)
            diffused_input += onehot(15-i);
    }
}
