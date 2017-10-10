#include <stdio.h>

#define MAXN 128

int
main()
{
	int	n, i;
	int	a, b, c, d;	
	int	cube[MAXN];

	scanf("%d", &n);
	// calculate the cubes first, avoiding overlapping calculation
	for (i = 2; i <= n; i++)
		cube[i] = i * i * i;
	// enumeration
	for (a = 6; a <= n; a++)
		for (b = 2; b < a; b++)
			for (c = b; cube[b] + cube[c] < cube[a]; c++) {
				for (d = c; cube[b] + cube[c] + cube[d] < cube[a]; d++); // skip
				if (cube[a] == cube[b] + cube[c] + cube[d])
					printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
			}

	return 0;
}
