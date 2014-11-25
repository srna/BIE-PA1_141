#include <stdio.h>
#include <stdlib.h>

#define INV printf("Invalid input file.\n"); return -1;

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

int main(int argc, char **argv)
{
	int *a,n,i;
	FILE* f;

	if(argc < 2)
	{
		printf("Usage: %s input_file\n", argv[0]);
		printf("File format: N elem1 elem2 ... elemN\n");
		return 0;
	}

	if(NULL == (f = fopen(argv[1], "r")))
	{
		printf("File %s does not exist.\n", argv[1]);
		return 1;
	}
	
	if(fscanf(f, "%d", &n) != 1) { INV };
	a = (int*)malloc(sizeof(int)*n);

	for(i = 0; i < n; i++) { if(fscanf(f, "%d", a+i) != 1) {INV} }

	printf("Original:    ");
	print_array(a, n);

	printf("Transformed: ");
	transform(a,n);
	print_array(a, n);

	fclose(f);
	free(a);
	return 0;
}

