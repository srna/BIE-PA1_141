#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
	printf("Enter the sides of the triangle [a b c]: ");
	if(3 != scanf("%lf %lf %lf", &a, &b, &c))
	{
		printf("Invalid input.\n");
		return 1;
	}
	if(a+b>c && b+c>a && c+a>b)
	{
		printf("The triangle CAN be constructed.\n");
	}
	else
	{
		printf("The triangle CAN'T be constructed.\n");
		return 0;
	}
	if((a == b) && (b == c))
	{
		printf("The triangle has equal sides.\n");
	}
	else if(a == b || b == c || c == a)
	{
		printf("The triangle has 2 equal sides.\n");
	}
	if(fabs(c*c - (a*a + b*b)) < c*c*1e-14)
	{
		printf("The triangle is right-angled.\n");
	}
	return 0;
}

