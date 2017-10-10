#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 128
#define UNMATCHED -1
#define MODE_MATCH 1
#define MODE_NORMAL 0

char	bxb(char, int);
void	print_path(int, int);
char	brackets[MAXLINE];
int	dp_value[MAXLINE][MAXLINE],
	dp_path[MAXLINE][MAXLINE];

int
main()
{
	int	len, minum, tmpv;
	int	i, j, n;

	while (fgets(brackets, MAXLINE, stdin) != NULL) {
		len = strlen(brackets) - 1;
		for (i = 0; i < len; i++) {
			dp_value[i][i] = 1;
			dp_path[i][i] = UNMATCHED;
			dp_value[i+1][i] = 0;	// edge protection
		}
		for (n = 1; n < len; n++) {	// n denotes the distance of subsequence
			for (i = 0; i + n < len; i++) {
				minum = dp_value[i+1][i+n] + 1;	// in case of not matching the first char
				dp_path[i][i+n] = UNMATCHED;
				for (j = i+1; j <= i + n; j++) {	// in case of matched
					if (bxb(brackets[i], MODE_MATCH) == brackets[j]) {
						tmpv = dp_value[i+1][j-1] + dp_value[j+1][i+n];
						if (minum > tmpv) {
							minum = tmpv;
							dp_path[i][i+n] = j;
						}
					}
				}
				dp_value[i][i+n] = minum;
			}
		}
		print_path(0, len - 1);
		putchar('\n');
	}
	
	return 0;
}

char
bxb(char b, int mode)	// bracket map to the matched
{
	char	xb;

	switch (b) {
		case '(':
			xb = ')';
			break;
		case '[':
			xb = ']';
			break;
		case ')':
			if (mode) xb = 'X';	// ')' and ']' could match theirs after them
			else xb = '(';
			break;
		case ']':
			if (mode) xb = 'X';
			else xb = '[';
			break;
		default:
			xb = 'X';	// 'X' denotes no matched character
	}

	return xb;
}

void
print_path(int start, int end)
{
	char	b, xb;

	if (start > end) return;

	b = brackets[start];
	xb = bxb(b, MODE_NORMAL);	
	if (dp_path[start][end] == UNMATCHED) {
		putchar(b < xb ? b : xb);	
		putchar(b > xb ? b : xb);
		print_path(start + 1, end);
	} else {
		putchar(b);
		print_path(start + 1, dp_path[start][end] - 1);
		putchar(xb);
		print_path(dp_path[start][end] + 1, end);
	}

}
