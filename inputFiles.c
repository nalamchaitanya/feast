#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc,char **argv)
{
	FILE *fp = fopen(argv[1],"w");
	int i,len;
	len = pow(2,atoi(argv[2]));
	i=0;
	while(i<len)
	{
		fputc(32+rand()%95,fp);
		i++;
	}
	fclose(fp);
	return 0;
}
