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

    FILE *fileptr;
    fileptr = fopen(argv[1],"r");

    FILE *filewrite;
    filewrite = fopen(argv[2],"w");

    int i,j,flag;
	char temp;

	char c;
	int input = 0;


	while(1)
	{
		for(i=0;i<4;i++)
		{
			c = fgetc(fileptr);
			if(c == EOF)
			{
				flag = 1;
				break;
			}
		}
		// if(flag == 1 && i == 0)
		// 	break;
		// else if (flag == 1)
		// {
		// 	fiestel(input);
		// 	printf("%x",input);
		// 	break;
		// }
		// else
		// {
		// 	fiestel(input);
		// 	printf("%x",input );
		// }

	}
    // Take 4 bytes at a time and convert to int and apply the encryption and
    // write into the output file. If you reach EOF then add '\0' at the end.
}
