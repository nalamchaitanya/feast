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
    int *keys = (int*)malloc(sizeof(int)*NO_OF_ROUNDS);
    int i = 0;
    char l1,l2,r1,r2;
}


void fileread()
{
    int i,j;
    char temp;

    sbox_arr = (int **)malloc(4*sizeof(int *));
    for(i=0;i<4;i++)
        sbox_arr[i] = (int *)malloc(16*sizeof(int));

    expansion_arr   = (int *)malloc(24*sizeof(int));
    diffusion_arr   = (int *)malloc(16*sizeof(int));

    FILE *fileptr;

    fileptr = fopen("exp.csv","r");
    for(i=0;i<24;i++)
        fscanf(fileptr,"%d%c",&expansion_arr[i],&temp);
    fflush(fileptr);
    fclose(fileptr);

    fileptr = fopen("diffu.csv","r");
    for(i=0;i<16;i++)
        fscanf(fileptr,"%d%c",&diffusion_arr[i],&temp);
    fflush(fileptr);
    fclose(fileptr);

    fileptr = fopen("s1.csv","r");
    for(i=0;i<4;i++)
        for(j=0;j<16;j++)
            fscanf(fileptr,"%d%c",&sbox_arr[i][j],&temp);
    fflush(fileptr);
    fclose(fileptr);

    return;
}

void fiestel(int input)
{
    int left,right,temp;
    int out_left,out_right,output;

    temp = 0x11110000;
    left = input && temp;

    temp = 0x00001111;
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
    int *array;
    array = (int *)malloc(32*sizeof(int));

    input = input ^ keys_arr[round_no];

    for(i=0;i<32;i++)
        array[i] = input && onehot(31-i);
}