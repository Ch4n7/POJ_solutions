#include <stdio.h>
#include <string.h>

#define MAXP 64	// maximum of the number of sticks parts
#define SUCC 0
#define FAIL -1 

int L, l;	// L - entire length; l - possible length of every single stick
int p;	// the number of parts
int sticks[MAXP];
int used[MAXP + 1];
int lastno;

void sort(int *, int);
int cat(int, int);

int
main()
{
	int	i, n;

	while (scanf("%d", &p) && p) {
		// readin 
		L = 0;
		for (i = 0; i < p; i++) {
			scanf("%d", sticks + i);
			L += sticks[i];
		}
		// sort, from long to short
		sort(sticks, p);
		// search the solution
		for (n = L / sticks[0]; n > 0; n--) {
			l = L / n;
			memset(used, 0, sizeof(used));
			if (cat(p, l) == SUCC) break;
		}
		// output
		printf("%d\n", l);
	}

	return 0;
}

void
sort(int *A, int n)	// insertion sort
{
	int	i, j;
	int	key;

	for (i = 1; i < n; i++) {
		key = A[i], j = i - 1;
		while (j >= 0 && A[j] < key)	// longer items first
			A[j + 1] = A[j], j--;
		A[j + 1] = key;
	}

	return;
}

int
cat(int nleft, int lleft)
{
	int	i;
	int	startno = 0;

	if (nleft == 0 && lleft == 0)
		return SUCC;
	if (lleft == 0)
		lleft = l;

	if (lleft != l)
		startno = lastno + 1;
	for (i = startno; i < p; i++) {
		if (!used[i] && sticks[i] <= lleft) {
			if (i > 0) {
				if (!used[i - 1] && sticks[i - 1] == sticks[i])
					continue;
			}
			used[i] = 1;
			lastno = i;
			if (cat(nleft - 1, lleft - sticks[i]) == SUCC)
				return SUCC;
			else {
				used[i] = 0;
				if (sticks[i] == lleft || lleft == l)
					return FAIL;
			}

		}
	}

	return FAIL;
}
