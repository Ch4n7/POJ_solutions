#include <stdio.h>

#define MAX_N 100000
#define MAX_X 1000000000
#define SUCC 1
#define FAIL 0

int n, c, stalls[MAX_N];
int sort(int A[], int n);
int check(int dist);

int
main()
{
	int i, left, right,
	    mid, ans;

	scanf("%d%d", &n, &c);
	for (i = 0; i < n; i++)
		scanf("%d", stalls + i);
	sort(stalls, n);
	left = 0;
	right = MAX_X;
	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid)) {
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	printf("%d\n", ans);

	return 0;
}

int
sort(int A[], int n)
{
	int i, j, smallest, tmp;

	for (i = 0; i < n - 1; i++) {
		smallest = i;
		for (j = i + 1; j < n; j++)
			if (A[j] < A[smallest])
				smallest = j;
		// swap A[i] with A[smallest]
		tmp = A[i];
		A[i] = A[smallest];
		A[smallest] = tmp;
	}
	
	return 0;
}

int
check(int dist)
{	
	int i,
	    last, next;

	last = 0;
	for (i = 1; i < c; i++) {
		next = last + 1;
		while (next < n && (stalls[next] - stalls[last]) < dist) next++;
		if (next == n)
			return FAIL;
		last = next;
	}

	return SUCC;
}
