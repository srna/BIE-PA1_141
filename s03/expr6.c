#include <stdio.h>

int main()
{
	int c = 2; 
	c+=++c++;
	printf("c = %d\n", c);
	return 0;
}


