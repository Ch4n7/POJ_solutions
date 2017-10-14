#include <stdio.h>
#define MAXN 64
#define MAXM 128

char DNA[MAXM][MAXN];
int  n, m, inv[MAXM], dna[MAXN];	// inv - inversion
int count();
int sort();

int
main()
{
	int	i;

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%s", DNA[i]);
	count(); // count the number of inversions in each NDA
	sort(); // sort the num of inversions	
	for (i = 0; i < m; i++)
		printf("%s\n", DNA[dna[i]]);

	return 0;
}

int
count()
{
	char	ch;
	int	i, j, k;

	for (k = 0; k < m; k++) {
		inv[k] = 0;
		for(i = 0; i < n - 1; i++) {
			ch = DNA[k][i]; 
			for (j = i + 1; j < n; j++)
				if (ch > DNA[k][j])
					inv[k]++;
		}
	}

	return 0;
}

// selection sort
int
sort()
{
	int	i, j, smallest, tmp;

	for (i = 0; i < m; i++)
		dna[i] = i;
	for (i = 0; i < m - 1; i++) {
		smallest = i;
		for (j = i + 1; j < m; j++) {
			if (inv[j] < inv[smallest])
				smallest = j;
		}
		// swap inv[smallest] and inv[i]
		tmp = inv[i];
		inv[i] = inv[smallest];
		inv[smallest] = tmp;
		// swap dna[smallest] and dna[i]
		tmp = dna[i];
		dna[i] = dna[smallest];
		dna[smallest] = tmp;
	}

	return 0;
}


