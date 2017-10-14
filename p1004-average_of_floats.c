#include <stdio.h>

int
main()
{
	int	i;
	float	avg, f;	// average

	avg = 0;
	for (i = 0; i < 12; i++) {
		scanf("%f", &f);
		avg += f;
	}
	avg /= 12;
	printf("$%.2f\n", avg);

	return 0;
}
