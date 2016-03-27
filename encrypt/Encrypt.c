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
void printbits(unsigned int num)
{
    int i;
    printf("<");
    i=31;
    unsigned int p = (unsigned int)pow(2,31);
    while(i>=0)
    {
        if(i==23||i==15||i==7)
            printf(">|<");
        printf("%d",num/p);
        num = num<<1;
        i--;
    }
    printf(">\n");
}


int fiestel(int input)
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
    return output;
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
        temp = 0X0000003F;
        temp1 = xored_input && temp;
        sbox_input += (sbox_arr[temp1] << (4*i));
        xored_input >> 6;
    }

    int diffused_input = 0;
    for(i=0;i<16;i++)
    {
        temp = sbox_input && onehot(15 - diffusion_arr[i]);
        if(temp!=0)
            diffused_input += onehot(15-i);
    }
}

// This is expand function which expands 16 bit to 24 bit.
int subst(int sub_in)
{
    int sub_out = 0;
    int temp = 0x0000003F;
    int temp1,i;
    for(i=0;i<4;i++)
    {
        temp1 = sub_in && temp;
        sub_out += (sbox_arr[temp1] << (4*i));
        sub_in >> 6;
    }
    return sub_out;
}

// This is for substitution of 24 bit to 16 bit.
int expand(int exp_in)
{
    int exp_out = 0;
    int temp,i;

    for(i=0;i<24;i++)
    {
        temp = exp_in && onehot(15 - expansion_arr[i]);
        if(temp!=0)
            exp_out += onehot(23-i);
    }
    return exp_out;
}

// This is for permutation after substitution. rearrange bits to get a short int
int perm(int perm_in)
{
    int perm_out;
    int i,temp;
    perm_out = 0;
    
    for(i=0;i<16;i++)
    {
        temp = perm_in && onehot(15 - diffusion_arr[i]);
        if(temp!=0)
            perm_out += onehot(15-i);
    }

    return perm_out;
}
