#include <stdio.h>
#define MAXN 100
#define MIN -127

int rec[MAXN][MAXN],
    row[MAXN][MAXN],
    sum[MAXN][MAXN];

int
main()
{
	int	n, i, j, k, l,
		max, s;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) 
			scanf("%d", rec[i] + j);
// row[i][j], the sum of the previous j items on ith row
	for (i = 0; i < n; i++) {
		row[i][0] = rec[i][0];
		for (j = 1; j < n; j++)
			row[i][j] = row[i][j - 1] + rec[i][j];
	}
// sum[i][j], the sum of the items in the rectangle from x(0, 0) to y(i, j)
// x . | . .
// . . | . .
// . . | . .
// _ _ y . .
// . . . . .
	for (j = 0; j < n; j++) {
		sum[0][j] = row[0][j];
		for (i = 1; i < n; i++)
			sum[i][j] = sum[i - 1][j] + row[i][j];
	}

// Base on the array sum, the sum of sub-rectangle can be computed.
	max = MIN; 
	for (i = 0; i < n - 1; i++)
		for (j = i; j < n; j++)
			for (k = 0; k < n - 1; k++)
				for (l = k; l < n; l++) {
					s = sum[j][l]
					-(i < 1 ? 0 : sum[i - 1][l])
					-(k < 1 ? 0 : sum[j][k - 1])
				+(i < 1 || k < 1 ? 0 : sum[i - 1][k - 1]);
					if (s > max)
						max = s;
				}
	printf("%d\n", max);

	return max;
}	
