#include <stdio.h>

int main()
{
	int h1, m1, h2, m2;
	int time1, time2, diff;
	
	printf("Enter Time 1 (hh:mm): ");
	scanf("%d :%d", &h1, &m1);
	printf("Enter Time 2 (hh:mm): ");
	scanf("%d :%d", &h2, &m2);

	time1 = h1*60+m1;
	time2 = h2*60+m2;

	diff = time2 - time1;
	if(diff<0) diff += 24*60;

	printf("The difference is %02d:%02d\n", diff/60, diff%60);

	return 0;
}

