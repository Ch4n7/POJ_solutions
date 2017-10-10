#include <stdio.h>
#include <math.h>

int
main()
{
	int	n, i;
	float	Vr, Vs, R, C, w;

	scanf("%f%f%f%d", &Vs, &R, &C, &n);
	for (i = 0; i < n; i++) {
		scanf("%f", &w);
		Vr = C * R * w * Vs / sqrtf(1 + C * C * R * R * w * w); 
		printf("%.3f\n", Vr);
	}

	return 0;
}
