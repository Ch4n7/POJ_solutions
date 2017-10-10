#include <stdio.h>
#define MAXL 128
#define MAX(x,y) ((x)<(y)?(y):(x))

int score['T' + 1]['T' + 1];	// 'T' is the biggest in ascii
int initial();

int
main()
{
	char	X[MAXL], Y[MAXL];
	int	t, T, i, j, m, n,
		opt[MAXL][MAXL];

	initial();
	scanf("%d", &T);	// the number of cases
	for (t = 0; t < T; t++) {
		scanf("%d%s", &m, X + 1);
		scanf("%d%s", &n, Y + 1);
		// Dynamic Programming
		// Base Cases
		opt[0][0] = 0;	// optimal score for two empty seq
		for (i = 1; i <= m; i++)
			opt[i][0] = opt[i - 1][0] + score[X[i]]['-'];
		for (j = 1; j <= n; j++)
			opt[0][j] = opt[0][j - 1] + score['-'][Y[j]];
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++) {
// Xi is the end of one of prefix of X,
// Yj is the end of one of prefix of Y.
// if Xi == Yj, then opt(i, j) = opt(i - 1, j - 1) + score(Xi, Xi).
				if (X[i] == Y[j])
					opt[i][j] = opt[i - 1][j -1] + score[X[i]][Y[j]];
				else {	// max of 3 options
// if Xi != Yj, there are 3 possiblities which could lead to the optimal
// 1. Xi match '-', then opt(i, j) = opt(i - 1, j) + score(Xi, '-').
// 2. Yj match '-', then opt(i, j) = opt(i, j - 1) + score('-', Yj).
// 3. Xi match Yj,  then opt(i, j) = opt(i - 1, j - 1) + score(Xi, Yj).
					opt[i][j] = MAX(opt[i - 1][j] + score[X[i]]['-'], opt[i][j - 1] + score['-'][Y[j]]);
					opt[i][j] = MAX(opt[i][j], opt[i - 1][j - 1] + score[X[i]][Y[j]]);
				}
			}
		printf("%d\n", opt[m][n]);
	}

	return 0;
}

int
initial()
{
	score['A']['A'] = 5;
	score['C']['C'] = 5;
	score['G']['G'] = 5;
	score['T']['T'] = 5;
	score['A']['C'] = score['C']['A'] = -1;
	score['A']['G'] = score['G']['A'] = -2;
	score['A']['T'] = score['T']['A'] = -1;
	score['A']['-'] = score['-']['A'] = -3;
	score['C']['G'] = score['G']['C'] = -3;
	score['C']['T'] = score['T']['C'] = -2;
	score['C']['-'] = score['-']['C'] = -4;
	score['G']['T'] = score['T']['G'] = -2;
	score['G']['-'] = score['-']['G'] = -2;
	score['T']['-'] = score['-']['T'] = -1; 
}// sparse 'score' matrix for a better runtime
// You can also use a index matrix and transform function from 'ACGT-' to 0..4
