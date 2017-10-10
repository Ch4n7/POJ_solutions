#include <stdio.h>
#include <algorithm>

#define MAX_N 100000
#define MAX_X 1000000000
#define SUCC 1
#define FAIL 0

using namespace std;

int n, c, stalls[MAX_N];
int check(int dist);

int
main()
{
	int i, left, right,
	    mid, ans;

	scanf("%d%d", &n, &c);
	for (i = 0; i < n; i++)
		scanf("%d", stalls + i);
	sort(stalls, stalls + n);
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
