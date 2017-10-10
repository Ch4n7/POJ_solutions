#include <stdio.h>
#include <string.h>

#define MAXK 14

int res[MAXK + 1];

int
main()
{
	int	k, m, pn, i, cnt;

	while (scanf("%d", &k) == 1 && k != 0) {
		if (res[k]) {	// save the result that was already computed, to fight against TLE error from POJ
			printf("%d\n", res[k]);
			continue;
		}

		for (m = k + 1; 7; m++) {	// 7 is my lucky number
			pn = 2 * k, i = 0;
			for (cnt = 0; cnt < k; cnt++) {
				i = (i + m - 1) % pn;	
				if (i < k)
					break;	// good guy executed!
				else 
					pn--;	// the number of rest people decreases	
			}
			if (cnt == k)
				break;	// 'm' found!
		}
		printf("%d\n", m), res[k] = m;
	}

	return 0;
}
