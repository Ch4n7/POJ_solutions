#include <stdio.h>

#define MAXP 64	// maximum of the number of sticks parts
#define SUCC 0
#define FAIL -1 

int L, l;	// L - entire length; l - possible length of every single stick
int p;	// the number of parts
int sticks[MAXP];
int used[MAXP + 1];

void sort(int *, int);
int cat(int, int, int);

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
			if (cat(n, 0, 0) == SUCC) break;
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
cat(int nleft, int lleft, int i)
{
	int	res, deadline;

	if (nleft == 0 && lleft == 0)
		return SUCC;
	if (nleft > 0 && lleft == 0) {
		for (i = 0; i < p; i++)
			if (!used[i]) break;
		used[i] = 1;
		// pick the longest available when start to combine a new original STICK
		res = cat(nleft - 1, l - sticks[i], i + 1);	
		used[i] = 0;
		return res;
	}

	deadline = lleft;
	for (; i < p; i++) {
		if (!used[i] && sticks[i] <= deadline) {
			used[i] = 1;
			res = cat(nleft, lleft - sticks[i], i + 1);
			used[i] = 0;

			if (res == SUCC)
				return SUCC;
			// if a stick perfectly fit the left length of the current STICK, and FAIL, then it must FAIL
			if (sticks[i] == lleft) break;	

			deadline = sticks[i] - 1;	// if FAIL, skip the sticks of the same length
		}
	}

	return FAIL;
}
