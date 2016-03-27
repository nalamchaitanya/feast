#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


    int i,j,flag;
	char temp;	

	global_variables();

	FILE *fileptr;
	fileptr = fopen(argv[1],"r");
	keygen();
	char c[4];
	int input = 0;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			char c = fgetc(fileptr);
			if(c == EOF)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1 && i == 0)
			break;
		else if (flag == 1)
		{
			fiestel(input);
			break;
		}
		else
			fiestel(input);

	}
    // Take 4 bytes at a time and convert to int and apply the encryption and
    // write into the output file. If you reach EOF then add '\0' at the end.
}
