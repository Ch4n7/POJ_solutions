#include <stdio.h>
#include <string.h>

#define MAXWORD 10000	// max length of pattern
#define MAXTEXT 1000000	// max length of text	
#define CHARSET 26

int next[MAXWORD + 1];
void build(char *, int);
void build_2(char *, int);
int KMP_match(char *, int, char *, int);

int
main()
{
	char	word[MAXWORD + 1],
		text[MAXTEXT + 1];
	int	n;

	scanf("%d\n", &n);
	while (n--) {
		scanf("%s", word);
		scanf("%s", text);
		build_2(word, strlen(word));
		printf("%d\n", KMP_match(text, strlen(text), word, strlen(word)));
	}

	return 0;
}

void
build(char *W, int lw)	// abcdx for x!=p[5]  1#p[1..4] = abcd 2#x!=p[5], here ignore 2#
{
	int j, k;

	next[0] = -1;
	next[1] = 0;
	for (j = 2; j <= lw; j++) {
		k = next[j - 1];
		while (k >= 0 && W[j - 1] != W[k])
			k = next[k];
		next[j] = k + 1;
	}
	
	return;
}

// Unseccessful - difference between f[] and next[]
/*
void
build_2(char *W, int lw)	// think of both 1# and 2#
{
	int	j, k;

	next[0] = -1;
	for (j = 1; j < lw; j++) {
		k = next[j - 1];
		while (k >= 0
			&& (W[j - 1] != W[k] || W[j] == W[k+1]))
				k = next[k];

		if (k < 0) {
			if (W[0] == W[j])
				next[j] = -1;
			else
				next[j] = 0;
		} else {
			next[j] = k + 1;
		}
	}
	// when fully matched, next[lw] how to represent? ignore #2 again - -!
	k = next[lw - 1];
	while (k >= 0 && W[j - 1] != W[k])
		k = next[k];
	next[lw] = k + 1;

	return;
}
*/

int
KMP_match(char *T, int lt, char *W, int lw)
{
	int	k, j;
	int	cnt;

	cnt = 0;
	k = j = 0;
	while (k < lt) {
		while (j >= 0 && T[k] != W[j])
			j = next[j];
		k++, j++;	// pointers move right only when j < 0 or T[k] == W[j]
		// is fully matched?
		if (j == lw) {
			cnt++;
			j = next[lw];
		}
	}

	return cnt;
}
