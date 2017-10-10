#include <stdio.h>

int
main()
{
	int	L, start, end;
	int	cnt;
	int	i, M;

	while (scanf("%d%d", &L, &M) == 2 
	    && !(L == 0 && M == 0)) {
		cnt = 0;
		for (i = 0; i < M; i++) {
			scanf("%d%d", &start, &end);
			cnt += end - start + 1;
		}
		printf("%d\n", L + 1 - cnt);
	}

	return 0;
}
