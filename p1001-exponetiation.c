#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 200 
#define MAXR 7
#define DOT ('.')

int
main()
{
	char	strR[MAXR];
	int	n;
	int	R[MAXN], intR, lenR;
	int	i, j;
	int	dot;	// to record the decimal places
	int	carry, tempn;
	int	start, end;

	while (scanf("%s%d", strR, &n) == 2) {
		// special cases #1
		if (n == 0) {
			printf("1\n");
			continue;
		}

		// deal with input: R[MAXN], n
		memset(R, 0, sizeof(R));
		dot = 0;
		lenR = strlen(strR);
		for (i = 0; i < lenR; i++) {
			if (strR[i] == DOT) {
				for (; i < lenR; i++) {
					strR[i] = strR[i+1];
					dot++;
				}
				dot--;	
				break;
			}
		}
		// special case #2
		if ((intR = atoi(strR)) == 0) {
			printf("0\n");
			continue;
		}
		lenR = strlen(strR);
		for (i = (lenR - 1), j = 0; i >= 0; i--, j++) 
			R[j] = strR[i] - '0';

		// bignum multiple	
		for (i = 1; i < n; i++) {
			carry = 0;	
			for (j = 0; j < MAXN; j++) {
				tempn = R[j] * intR + carry;
				R[j] = tempn % 10;
				carry = tempn / 10;
			}
		}

		// deal with output
		dot *= n;	// the decimal places in result	
		for (i = 0; i < dot && R[i] == 0; i++);
		end = i;
		for (i = MAXN - 1; i >= dot && R[i] == 0; i--);
		start = i;
		for (i = start; i >= end; i--) {
			if (i == (dot - 1)) printf("%c", DOT);
			printf("%d", R[i]);
		}
		printf("\n");
	}

	return 0;
}
