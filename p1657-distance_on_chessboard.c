#include <stdio.h>
#include <stdlib.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int
main()
{
	int	t;
	char	srcx, desx;
	int	srcy, desy;
	int	distx, disty;
	int	i;

	scanf("%d", &t);
	getchar();
	for (i = 0; i < t; i++) {
		scanf("%c%d %c%d", &srcx, &srcy, &desx,  &desy);
		getchar();
		distx = abs(desx - srcx);
		disty = abs(desy - srcy);
		// Special Case: no need to move
		if (!distx && !disty) {
			printf("0 0 0 0\n");
			continue;
		}
		// king
		printf("%d", MAX(distx, disty));
		putchar(' ');
		// queen
		if (!distx || !disty || distx == disty)
			printf("%d", 1);
		else
			printf("%d", 2);
		putchar(' ');
		// Rook
		if (!distx || !disty)
			printf("%d", 1);
		else
			printf("%d", 2);
		putchar(' ');
		// Bishop
		if (distx == disty)
			printf("%d", 1);
		else if (distx % 2 == disty % 2)
			printf("%d", 2);
		else
			printf("Inf");
		putchar('\n');
	}

	return 0;
}
