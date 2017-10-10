// This is not an accurate anwser, but it got AC on poj.
//
// If a num is cyclic, then the sum of all digits whenever 
// multiplied by an integer from 1 to n, the length of the
// num.
// Otherwise, it will hardly get the same sum of all digits.
//
// This is the basic idea of this code.

#include <stdio.h>
#include <string.h>

#define MAXN 64

char str[MAXN];
int num[MAXN], mul[MAXN];
int sum(int *A, int l);

int
main()
{
	int	i, k, l, s,
		carry, flag;

	while (gets(str) != NULL) {
		flag = 1;
		l = strlen(str);	
		for (i = 0; i < l; i++)
			num[l - 1 - i] = str[i] - '0';
		s = sum(num, l);
		for (k = 2; k <= l; k++) {
			carry = 0;
			for (i = 0; i < l; i++) {
				mul[i] = num[i] * k + carry;
				carry = mul[i] / 10;
				mul[i] = mul[i] % 10;
			}
	// sum() is the feature that won't change
	// through all the multiplications.
			if (sum(mul, l) != s) {	
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%s is cyclic\n", str);
		else
			printf("%s is not cyclic\n", str);
	}
}

int
sum(int *A, int l)
{
	int	i, sum;

	sum = 0;
	for (i = 0; i < l; i++) {
		sum += A[i];
	}

	return sum;
}
