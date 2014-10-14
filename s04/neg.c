#include <stdio.h>

int main()
{
	int a;
	printf("Enter an integer: ");
	if(1 != scanf("%d", &a))
	{
		printf("Invalid input.\n");
		return 1;
	}

	if(a == 0)
	{
		/* If the number is zero */
		printf("The number is zero.\n");
	}
	else if(a < 0)
		printf("The number is negative.\n");
	else
		printf("The number is positive.\n");

	return 0;
}

