#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int len)
{
	int i;
	printf("[");
	for(i = 0; i < len; i++)
	{
		printf("%d", a[i]);
		if(i != len-1)
			printf(" ");
	}
	printf("]\n");
}

void transform(int *a, int n)
{
	int i=0,j=n-1,tmp;
	while(i<j)
	{
		while(i<j && a[i] % 2 == 0) i++;
		while(i<j && a[j] % 2 == 1) j--;
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

int main()
{
	int *a,n,i;
	printf("Number of elements: ");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);

	printf("Enter the numbers: ");
	for(i = 0; i < n; i++) { scanf("%d", a+i); }

	printf("Original:    ");
	print_array(a, n);

	printf("Transformed: ");
	transform(a,n);
	print_array(a, n);

	free(a);
	return 0;
}

