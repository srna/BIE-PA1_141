#include <stdio.h>

int get_min(int a, int b)
{
	return (a<b ? a : b);
}

void get_minmax(int a, int b, int *min, int *max)
{
	*min = (a<b ? a : b);
	*max = (a>b ? a : b);
}

int main()
{
	int a, b, min, max;
	printf("Enter 2 numbers: ");
	if(scanf("%d%d", &a, &b) != 2) { printf("Invalid input.\n"); return 1; }
	printf("Minimum is %d\n", get_min(a,b));

	get_minmax(a, b, &min, &max);
	printf("Min: %d\nMax: %d\n", min, max);

	return 0;
}

