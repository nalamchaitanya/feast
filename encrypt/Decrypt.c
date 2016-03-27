#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Encrypt.h"

// Take command line arguments of files input and output.
// Usage: ./Feast <Input File> <Encrypted File>

int main(int argc,char **argv)
{
    if(argc!=3)
    {
        printf("Usage: ./Feast <Input File> <Encrypted File>\n");
        exit(0);
    }

    keys_arr[0] = 6;
    keys_arr[1] = 5;
    keys_arr[2] = 4;
    keys_arr[3] = 3;
    keys_arr[4] = 2;
    keys_arr[5] = 1;

    FILE *fileptr;
    fileptr = fopen(argv[1],"r");

    FILE *filewrite;
    filewrite = fopen(argv[2],"w");

    int i,j,flag,output,temp1;
	char temp;	

	char c;
	int input = 0;

	flag = 0;

	while(1)
	{
		input = 0;
		
		for(i=0;i<4;i++)
		{
			c = fgetc(fileptr);

			if(c == EOF)
			{
				flag = 1;
				break;
			}
//			printf("%c\n",c);
			temp1 = (int)c << (24-8*i);
			input = input + temp1;
		}
//		printf("%x",input);
		
//		input = (input>>16)|(input<<16);

		if(flag == 1 && i == 0)
			break;
		else if (flag == 1)
		{
			output = fiestel(input);
			write(output,filewrite);
//			printf("%x\n",output);
			break;
		}
		else
		{
			output = fiestel(input);
			write(output,filewrite);
//			printf("%x\n",output );
		}
	}

	fflush(filewrite);
	fclose(filewrite);

	fflush(fileptr);
	fclose(fileptr);
    // Take 4 bytes at a time and convert to int and apply the encryption and
    // write into the output file. If you reach EOF then add '\0' at the end.
}

