#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helper.h"

// All function implementations here.

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
}

void generatekeys()
{
	int i,j;
	keys_arr = (char **)malloc(NO_OF_ROUNDS * sizeof(char *));
	for(i=0;i<NO_OF_ROUNDS;i++)
		keys_arr[i] = (char *)malloc(KEY_SIZE * sizeof(char));	

	return;
}

void fiestel(char *input)
{
	int i,j;
	
	char *left,*right;
	char *out_left,*out_right,*output,*temp_arr;

	left  = (char *)malloc((INPUT_SIZE/2) * sizeof(char));
	right = (char *)malloc((INPUT_SIZE/2) * sizeof(char));

	out_left  = (char *)malloc((INPUT_SIZE/2) * sizeof(char));
	out_right = (char *)malloc((INPUT_SIZE/2) * sizeof(char));
	output    = (char *)malloc( INPUT_SIZE    * sizeof(char));

	temp_arr  = (char *)malloc((INPUT_SIZE/2) * sizeof(char));

	for(i=0;i<INPUT_SIZE/2;i++)
	{
		left[i]  = input[i];
		right[i] = input[i+(INPUT_SIZE/2)];
	}

	for(i=0;i<NO_OF_ROUNDS;i++)
	{
		out_left = right;
		function(right,temp_arr,i);
		xor(left,temp_arr,out_right,INPUT_SIZE/2);
		left = out_left;
		right = out_right;
	}

	for(i=0;i<INPUT_SIZE/2;i++)
	{
		output[i] = out_left[i];
		output[i+(INPUT_SIZE/2)] = out_right[i];
	}

	for(i=0;i<INPUT_SIZE;i++)
		printf("%c",output[i]);

}

void function(char *input,char *output,int round_no)
{
	int i,j,temp;

	char *expanded_arr;
	char *compressed_arr;
	char *diffused_arr;
	char *temp_arr;

	int row_no,col_no;

	expanded_arr    = (char *)malloc(24 * sizeof(char));
	temp_arr        = (char *)malloc(24 * sizeof(char));
	compressed_arr  = (char *)malloc(16 * sizeof(char));

	for(i=0;i<24;i++)
		expanded_arr[i] = input[expansion_arr[i]];

	xor(expanded_arr,keys_arr[round_no],temp_arr,24);

	for(i=0;i<4;i++)
	{
		row_no = ((int)temp_arr[6*i]-48)*2 + (int)temp_arr[6*i+5]-48;
		col_no = ((int)temp_arr[6*i+1]-48)*8 + ((int)temp_arr[6*i+2]-48)*4 + ((int)temp_arr[6*i+3]-48)*2 + (int)temp_arr[6*i+4]-48;
		temp   = sbox_arr[row_no][col_no];
		compressed_arr[4*i+3] = (temp%2)+'0';
		temp = temp/2;
		compressed_arr[4*i+2] = (temp%2)+'0';
		temp = temp/2;
		compressed_arr[4*i+1] = (temp%2)+'0';
		temp = temp/2;
		compressed_arr[4*i]   = (temp%2)+'0';
		temp = temp/2;
	}

	for(i=0;i<16;i++)
		output[i] = compressed_arr[diffusion_arr[i]];

	return;
}

void xor(char *arr1,char *arr2,char *output,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr1[i] == arr2[i])
			output[i] = '0';
		else
			output[i] = '1';
	}
	return;
}
