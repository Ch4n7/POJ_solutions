#include <stdio.h>
#define MAXN 101
#define MIN -127

int rec[MAXN][MAXN],
    col[MAXN][MAXN];

int
main()
{
	int	n, i, i1, i2, j,
		max, sum;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) 
			scanf("%d", rec[i] + j);
// rec[*][0] and rec[0][*] are padded with 0s,
// to keep the computation clean.
	for (i = 0; i <= n; i++)
		rec[i][0] = 0;
	for (j = 0; j <= n; j++)
		rec[0][j] = 0;
	for (j = 1; j <= n; j++)
		for (i = 1; i <= n; i++)
			col[i][j] = col[i - 1][j] + rec[i][j];
// Maximum Subarray Problem applied to 2-dimension
//   ........
//i1 --------
//   ........
//   ........
//i2 --------
//   ........
//
//   ||||||||
//B  xxxxxxxx   
//Bj, is the sum of the items from i1th row
//to i2th row in the jth col.
//Then apply the MaxSub Algorithm on the array B.
	max = MIN; 
	for (i1 = 0; i1 < n; i1++)
		for (i2 = i1 + 1; i2 <= n; i2++) {
			sum = 0;
			for (j = 1; j <= n; j++) {
				sum += col[i2][j] - col[i1][j];
				if (sum > max) max = sum;
				if (sum < 0) sum = 0;
			}
		}

	printf("%d\n", max);

	return 0;
}	
