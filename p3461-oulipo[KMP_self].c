#include <stdio.h>
#include <string.h>

#define MAXWORD 10000	// max length of pattern
#define MAXTEXT 1000000	// max length of text	
#define CHARSET 26

int next[MAXWORD + 1];
void build(char *, int);
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
		build(word, strlen(word));
		printf("%d\n", KMP_match(text, strlen(text), word, strlen(word)));
	}

	return 0;
}

void
build(char *W, int l)
{
	int	i, k;
	
	next[0] = -1;
	next[1] = 0;
	for (i = 2; i <= l; i++) {
		next[i] = 0;
		k = next[i-1];
		while (k >= 0) {
			if (W[i-1] == W[k]) {
				next[i] = k + 1;
				break;
			} else {
				k = next[k];
			}
		}
	}
	return;
}

int
KMP_match(char *T, int lt, char *W, int lw)
{
	int	cnt, i, j;

	cnt = 0;
	for (i = 0, j = 0; i < lt;) {
		if (T[i] == W[j]) {
			if (j == lw - 1) {
				cnt++;
				i++, j = next[lw];
			} else {
				i++, j++;
			}
		} else {
			j = next[j];
			if (j < 0) {
				i++, j = 0;
			}
		}
	}


	return cnt;
}
