#include <stdio.h>
#include "Encrypt.h"

int main()
{
	int a,b,c;
	a = perm(1);
	b = subst(1);
	c = expand(3);
	printbits(4);
	printbits(a);
	printbits(b);
	printbits(c);
	write(0x10000000,fopen("temp.txt","w"));
	return 0;
}
