#include <stdio.h>
#define SQ(x) ((x)*(x))		// self-defined square formula
#define TARGETN 16

int
main()
{
	int	t[TARGETN][3],	// target colors
		r, g, b;	// to-mapped color's RGB value
	int	dist,		// the square of the dist
		d;		// the least distance	
	int	i, c;

	for (i = 0; i < TARGETN; i++)
		scanf("%d%d%d", t[i] + 0,t[i] + 1, t[i] + 2);

	while (scanf("%d%d%d", &r, &g, &b) == 3
	    && !(r == -1 && g == -1 && b == -1)) {
		d = 255*255*3 + 1;		// initiate to maximum
		for (i = 0; i < TARGETN; i++) {
			dist = SQ(r - t[i][0]) 
			     + SQ(g - t[i][1])
			     + SQ(b - t[i][2]);
			if (dist < d) {
				d = dist;
				c = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b,
				t[c][0], t[c][1], t[c][2]);
	}

	return 0;
}
