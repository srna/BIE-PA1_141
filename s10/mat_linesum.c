#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int mat_t;

int mat_read(FILE * f, mat_t ** mat, int N, int M)
{
	int i,j;
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(1 != fscanf(f, "%d", &(mat[i][j])))
				return 0;
		}
	}
	return 1;
}

void mat_write(FILE *f, mat_t ** mat, int N, int M)
{
	int i,j;
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			fprintf(f, "%d ", mat[i][j]);
		}
		fprintf(f,"\n");
	}
}

mat_t mat_gls(mat_t **mat, int N, int M)
{
	int ls, gls = INT_MIN;
	int i,j;
	for(i = 0; i < M; i++)
	{
		ls=0;
		for(j=0;j<N;j++)
			ls+=mat[i][j];
		if(ls > gls) gls = ls;
	}
	return gls;
}

int main(int argc, char**argv)
{
	int N,M,i;
	mat_t ** mat;
	FILE* f;

	if(argc < 2)
	{
		printf("Usage: %s input_file\n", argv[0]);
		printf("File format:\n"
		       "N M\n"
		       "a11 .. a1N\n"
		       ".        .\n"
		       ".        .\n"
		       "a1M .. aNM\n");
		return 0;
	}

	f = fopen(argv[1], "r");

	if(NULL == (f = fopen(argv[1], "r")))
	{
		printf("File %s does not exist.\n", argv[1]);
		return 1;
	}

	if(2 != fscanf(f, "%d%d", &N, &M) || N < 1 || M < 1)
	{
		printf("Invalid matrix dimensions\n");
		return 2;
	}

	mat = (int**)malloc(M*sizeof(int*));
	for(i = 0; i < M; i++)
	{
		mat[i] = malloc(N*sizeof(int));
	}
	
	if(!mat_read(f, mat, N, M))
	{
		printf("Invalid input file.\n");
		return -1;
	}

	printf("The matrix:\n");
	mat_write(stdout, mat, N, M);

	printf("The greatest line sum: %d\n", mat_gls(mat, N, M));

	return 0;
}

