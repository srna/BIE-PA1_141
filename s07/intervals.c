#include <stdio.h>

void sanitize(int *left, int *right) { int tmp; if(*left <= *right) return; tmp = *left; *left = *right; *right = tmp; }
int min(int a, int b) { return (a<b ? a : b); } 
int max(int a, int b) { return (a>b ? a : b); }
void intersection(int left1, int right1, int left2, int right2, int *left, int *right) {
	sanitize(&left1, &right1); sanitize(&left2, &right2);
	*left = max(left1, left2); *right = min(right1, right2);
	if(*left > *right) *left = *right = 0; }

int main()
{
	int left1, right1, left2, right2;
	int left, right;

	printf("Enter interval 1: ");
	if(scanf("%d%d", &left1, &right1) != 2) { printf("Invalid input.\n"); return 1; }

	printf("Enter interval 2: ");
	if(scanf("%d%d", &left2, &right2) != 2) { printf("Invalid input.\n"); return 1; }

	intersection(left1, right1, left2, right2, &left, &right);

	printf("The intersection is <%d,%d>.\n", left, right);

	return 0;
}

