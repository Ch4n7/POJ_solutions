// TLE
#include <stdio.h>
#include <string.h>

#define MAXK 14

int people[MAXK * 2], pn;
int k;
int next(int);

int
main()
{
	int	m, i, s, cnt;

	while (scanf("%d", &k) == 1 && k != 0) {
		for (m = k + 1; 7; m++) {	// 7 is my lucky number
			memset(people, 0, sizeof(people)), pn = 2 * k, i = 0;
			for (cnt = 0; cnt < k; cnt++) {
				for (s = 0; s < (m - 1) % pn; s++)
					i = next(i);
				if (i < k)
					break;	// good guy executed!
				else {
					people[i] = 1;	// ith people executed
					pn--;	// the number of rest people decreases	
					i = next(i);	// start from the next one
				}
			}
			if (cnt == k)
				break;	// 'm' found!
		}
		printf("%d\n", m);
	}

	return 0;
}

int
next(int i)
{
	i = (i + 1) % (2 * k);	// not include 'i'
	while (people[i] != 0) {
		i = (i + 1) % (2 * k);
	}

	return i;
}
