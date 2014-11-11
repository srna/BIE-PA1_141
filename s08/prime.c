#include <stdio.h>

void print_factor(int num)
{
	int i;
	if(num < 2) return;
	for(i = 2; i <= num; i++)
	{
		if(num % i == 0)
		{
			printf("%d\n", i);
			break;
		}
	}
	print_factor(num/i);
}

int main()
{
	int n;
	printf("Enter number: ");
	if(scanf("%d", &n) != 1) { printf("Invalid input.\n"); return 1; }
	printf("The prime factorisation of %d is:\n", n);
	print_factor(n);
	return 0;
}

