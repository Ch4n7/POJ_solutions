#include <stdio.h>
#include <string.h>
#define MAXLEN 256 

int
main()
{
	char	X[MAXLEN],
		Y[MAXLEN];
	int	m, n;
	int	l[MAXLEN][MAXLEN];
	int	i, j;

	while (scanf("%s%s", X + 1, Y + 1) != EOF) {	// put string into X[1..m], Y[1..n] for dp's clearness
		m = strlen(X + 1);
		n = strlen(Y + 1);
		for (i = 0; i <= m; i++)
			l[i][0] = 0;
		for (j = 0; j <= n; j++)
			l[0][j] = 0;
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
				if (X[i] == Y[j])
					l[i][j] = l[i-1][j-1] + 1;
				else if (l[i-1][j] > l[i][j-1])
					l[i][j] = l[i-1][j];
				else
					l[i][j] = l[i][j-1];
		printf("%d\n", l[m][n]);
	}

	return 0;
}
