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
        temp1 >> 8;
    }

    int diffused_input = 0;
    for(i=0;i<24;i++)
    {
        temp = input && onehot(15 - expansion_arr[i]);
        if(temp!=0)
            diffused_input += onehot(15-i); 
    }
}