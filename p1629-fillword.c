#include <stdio.h>
#include <string.h>

#define CHARSET 26

int
main()
{
	int	cnts[CHARSET];
	int	n, m, p;
	int	i, j;
	char	ch;

	memset(cnts, 0, sizeof(cnts));
	scanf("%d%d%d\n", &n, &m, &p);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%c", &ch);
			cnts[ch - 'A']++;
		}
		getchar();
	}
	for (i = 0; i < p; i++)
		while (scanf("%c", &ch) == 1 && ch != '\n') 
			cnts[ch - 'A']--;
	for (i = 0; i < CHARSET; i++)
		while (cnts[i]--)
			putchar('A' + i);

	return 0;
}
