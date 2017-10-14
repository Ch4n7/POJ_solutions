#include <stdio.h>
#include <math.h>

#define POW2(x) ((x)*(x))
#define PI 3.1415926

int
main()
{
	int	n, i, z;
	double	x, y, s;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lf%lf", &x, &y);
		s = PI / 2 * (POW2(x) + POW2(y));
		z = ceil(s / 50);
		printf("Property %d: This property will begin eroding in year %d.\n", i, z);
	}
	printf("END OF OUTPUT.\n");

	return 0;
}
