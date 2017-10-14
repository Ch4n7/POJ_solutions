#include <stdio.h>
#define MAXR 128
#define MAXC 128

int r, c,
    h[MAXR][MAXC],	// heights
    l[MAXR][MAXC];	// max length on each point
int bfs(int, int);	// breadth first to search the points map - h[][]

int
main()
{
	int	i, j, max, ans;

	scanf("%d%d", &r, &c);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", h[i] + j);
	max = 0;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			ans = bfs(i, j);	
			if (max < ans)
				max = ans;
		}

	printf("%d\n", max);

	return 0;
}

// return the length of the longest dcreasing seq
// that starts from point (i, j)
int
bfs(int i, int j)	
{
	int	max, ans;

	if (l[i][j] > 0)
		return l[i][j];

	max = 0;
	// upper, if the height is lower than h(i, j), then move on 
	if (i - 1 >= 0 && h[i][j] > h[i - 1][j]) {
		ans = bfs(i - 1, j);
		if (max < ans) max = ans;
	}
	// down, .. 
	if (i + 1 < r && h[i][j] > h[i + 1][j]) {
		ans = bfs(i + 1, j);
		if (max < ans) max = ans;
	}
	// left, ..
	if (j - 1 >= 0 && h[i][j] > h[i][j - 1]) {
		ans = bfs(i, j - 1);
		if (max < ans) max = ans;
	}
	// right, ..
	if (j + 1 < c && h[i][j] > h[i][j + 1]) {
		ans = bfs(i, j + 1);
		if (max < ans) max = ans;
	}

	// 5 ways to get the l(i, j): up, down, left, right, and
	// if (i, j) is the lower than all the directions,
	// just set l[i][j] to 1.
	l[i][j] = max  + 1;

	return l[i][j];
}
