#include <stdio.h>
#include <string.h>

#define MAXWORD 10000	// max length of pattern
#define MAXTEXT 1000000	// max length of text	
#define CHARSET 26

void build(char *, int);
int FA_match(char *, int, int);

int	next_state[MAXWORD + 1][CHARSET];

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
		memset(next_state, 0, sizeof(next_state));
		build(word, strlen(word));
		printf("%d\n", FA_match(text, strlen(text), strlen(word)));
	}

	return 0;
}

void
build(char *W, int l)
{
	int	k, c, i;
	char	a;
	
	for (k = 0; k < l; k++) {
		for (c = 0; c < CHARSET; c++) {
			a = 'A' + c;
			for (i = k; i >= 0; i--) {
				if (W[i] == a && strncmp(W, W + k - i, i) == 0) {
						next_state[k][c] = i + 1;
						break;
					}
			}
			if (i == -1)	// -1 means no prefix and suffix match
				next_state[k][c] = 0;
		}
	}

	for (c = 0; c < CHARSET; c++) {
		a = 'A' + c;
		for (i = l - 1; i >= 0; i--) {
			if (W[i] == a && strncmp(W, W + l - i, i) == 0) {
				next_state[l][c] = i + 1;
				break;
			}
		}
		if (i == -1)
			next_state[l][c] = 0;
	}

	return;
}

int
FA_match(char *T, int l, int goal)
{
	int	cnt, k, i;

	cnt = 0;
	k = 0;
	for (i = 0; i < l; i++) {
		k = next_state[k][(T[i] - 'A')];
		if (k == goal) cnt++;
	}

	return cnt;
}
