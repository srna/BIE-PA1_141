#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char first[20];
	char last[20];
	int year;
	double average;
} student;

typedef struct {
	student *students;
	int size;
	int count;
} dynarr;

void print_student(const student *s)
{
	printf("[%s %s, born %d, average %.2f]", s->first, s->last, s->year, s->average);
}

void dynarr_init(dynarr *d)
{
	d->students = (student*)malloc(2*sizeof(student));
	d->size = 2;
	d->count = 0;
}

void dynarr_adjust(dynarr *d, int newcount)
{
	if(d->size < newcount)
	{
		d->students = (student*)realloc(d->students, d->size*2*sizeof(student));
		d->size *= 2;
	}
}

void dynarr_insert(dynarr *d, const student *s)
{
	dynarr_adjust(d, d->count+1);
	d->students[d->count] = *s;
	d->count ++;
}

void dynarr_free(dynarr *d)
{
	free(d->students);
}

int student_cmpavg(const void *a, const void *b)
{
	const student *sa = (const student*)a;
	const student *sb = (const student*)b;

	if(sa->average < sb->average)
		return -1;
	if(sa->average > sb->average)
		return 1;
	return 0;
}

int main()
{
	int i;
	dynarr d;
	student tmp;

	dynarr_init(&d);

	printf("Insert students in format[first last year avg] and end with Ctrl+D\n");
	while(scanf("%s %s %d %lf", tmp.first, tmp.last, &tmp.year, &tmp.average) == 4)
		dynarr_insert(&d, &tmp);

	printf("The students (in the order of entrance):\n");
	for(i=0;i<d.count;i++)
	{
		print_student(d.students+i);
		printf("\n");
	}

	printf("The students (in the order of average):\n");
	qsort(d.students, d.count, sizeof(student), student_cmpavg);
	for(i=0;i<d.count;i++)
	{
		print_student(d.students+i);
		printf("\n");
	}

	dynarr_free(&d);

	return 0;
}

