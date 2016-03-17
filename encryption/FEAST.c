#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Should take the input and output file as command line arguments and encrypt
// using DES and exit.

int main()
{
	int i,j,flag;
	char temp;	

	fileread();
	generatekeys();

	for(i=0;i<NO_OF_ROUNDS;i++)
		for(j=0;j<KEY_SIZE;j++)
			keys_arr[i][j] = '1';

	keys_arr[0][0] = '0';
	keys_arr[1][1] = '0';
	keys_arr[2][2] = '0';
	keys_arr[3][3] = '0';
	keys_arr[4][4] = '0';
	keys_arr[5][5] = '0';

	FILE *fileptr;
	fileptr = fopen("input.txt","r");

	char *input;
	input = (char *)malloc(INPUT_SIZE * sizeof(char));

	if(fileptr == NULL)
	{
		printf("no input");
		exit(1);
	}

	flag = 0;

	while(1)
	{
		if(flag == 1)
			break;

		for(i=0;i<INPUT_SIZE;i++)
			input[i] = '0';

		for(i=0;i<INPUT_SIZE;i++)
		{
			temp = fgetc(fileptr);
			if(temp != '0' && temp!= '1' )
			{
				flag = 1;
				break;
			}
			input[i] = temp;
		}

		fiestel(input);

	}

	fflush(fileptr);
	fclose(fileptr);
}

