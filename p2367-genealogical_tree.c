#include <stdio.h>
#include <string.h>

#define MAXN 101
#define OUT 0xffff

int
main()
{
	int	i, j, k, n, child;
	int	adj_matrix[MAXN][MAXN],
		indegrees[MAXN];

	memset(adj_matrix, 0, sizeof(adj_matrix));
	memset(indegrees, 0, sizeof(indegrees));
	// deal with the input
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		while ((scanf("%d", &child) == 1) && (child != 0)) {
			adj_matrix[i][child] = 1;
			indegrees[child]++;
		}
	}
	// topological sort
	for (i = 1; i <= n; i++)	// n vertices to output
		for (j = 1; j <= n; j++) {	// search the first vertices whose indegree is 0
			if (indegrees[j] == 0) {
				// print
				printf("%d", j);
				if (i == n)
					printf("\n");
				else
					printf(" ");
				// delete
				indegrees[j] = OUT;
				// decrease
				for (k = 1; k <= n; k++) 
					if (adj_matrix[j][k] == 1) 
						indegrees[k]--;

				break;	// output only one at a time
			}
		}
	
	return 0;
}
