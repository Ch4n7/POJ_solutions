#include <stdio.h>
#include <string.h>

#define MAX_N 512
#define MAX_T 10001 

int adj_matrix[MAX_N][MAX_N];
int shortest[MAX_N];

int
main()
{
	int	farms, fields, 
		paths, wormholes,
		i, s, e, t;

	scanf("%d", &farms);
	while (farms--) {
		// readin
		scanf("%d%d%d", &fields, &paths, &wormholes);
		memset(adj_matrix, MAX_T, sizeof(adj_matrix));
		for (i = 0; i < paths; i++) {
			scanf("%d%d%d", &s, &e, &t);	
			// might be connected by more than one path between two fields.
			// choose the shortest
			if (adj_matrix[s][e] > t) {	
				adj_matrix[s][e] = t;
				adj_matrix[e][s] = t;	// bidirectional path
			}
		}
		for (i = 0; i < wormholes; i++) {
			scanf("%d%d%d", &s, &e, &t);
			adj_matrix[s][e] = -t;
		}
		for (i = 0; i < fields; i++)	// add a new vertex with 0-weigth edge to others
			adj_matrix[0][i] = 0;
		// bellman-ford
		memset(shortest, MAX_T, sizeof(shortest));
		shortest[0] = 0;
		for (i = 0; i < fields - 1; i++)	// n - 1 turns
			for (s = 0; s <= fields; s++)	
				for (e = 1; e <= fields; e++) { // traverse all the paths
					t = shortest[s] + adj_matrix[s][e];
					if (shortest[e] > t)
						shortest[e] = t;
				}
		// find negative cycle and writeout
		for (s = 0; s <= fields; s++)
			for (e = 1; e <= fields; e++)
				if (shortest[e] > shortest[s] + adj_matrix[s][e]) {
						printf("YES\n");
						goto NEXT_FARM;
				}
		printf("NO\n");

		NEXT_FARM:;
	}

	return 0;
}
