#include <stdio.h>
#include <string.h>

#define MAXN 26
// for adjacent matrix
#define PRESENT 1
#define ABSENT 0
// for flag
#define DONE 1
#define NOT_YET 0
// for next list
#define IN 1
#define OUT 0
#define MAX(x,y) ((x) > (y) ? (x) : (y))

int	adj_matrix[MAXN][MAXN];
char	seq[MAXN+1];	// sorted seqeunce
int	n, m;

int	run();
int	count(int*);
int	find(int*);

int
main()
{
	int	r;
	char	chu, chv;
	int	u, v;
	int	flag;

	while ((scanf("%d%d", &n, &m) == 2) && !(n == 0 && m == 0)) {
		getchar();

		flag = NOT_YET;
		memset(adj_matrix, ABSENT, sizeof(adj_matrix));
		r = 0;
		while (r < m) {
			scanf("%c<%c\n", &chu, &chv), r++;
			u = chu - 'A';
			v = chv - 'A';
			adj_matrix[u][v] = PRESENT;
			switch (run()) {
				case 0:	// cannot give a result yet
					continue;
				case 1:
					printf("Sorted sequence determined after %d relations: %s.\n", r, seq);
					flag = DONE;
					break;
				case 2:
					printf("Inconsistency found after %d relations.\n", r);
					flag = DONE;
					break;
			}
			for (; r < m; r++)
				scanf("%c<%c\n", &chu, &chv);	// skip the remains
		}
		if (flag != DONE)
			printf("Sorted sequence cannot be determined.\n");
	}

	return 0;
}

int
run()
{
	int	in_degree[MAXN];
	int	next[MAXN];
	int	cnt, cnt_max;
	int	u, v;
	int	i;
	int	ret;

	// in-degree[]
	memset(in_degree, 0, sizeof(in_degree));
	for (u = 0; u < n; u++)
		for (v = 0; v < n; v++)
			if (adj_matrix[u][v] == PRESENT)
				in_degree[v]++;
	// next[]
	memset(next, OUT, sizeof(next));
	for (u = 0; u < n; u++)
		if (!in_degree[u])
			next[u] = IN;
	i = 0;
	cnt_max = 0;
	while (cnt = count(next)) {
		cnt_max = MAX(cnt, cnt_max);
		u = find(next);
		seq[i] = u + 'A', seq[i+1] = '\0', i++;	// always give a ending, so that no need to initialize seq[]
		next[u] = OUT;
		for (v = 0; v < n; v++)
			if (adj_matrix[u][v] == PRESENT) {
				in_degree[v]--;
				if (!in_degree[v])
					next[v] = IN;
			}
	}

	if (i != n)	// there is remaining vertice after the topological sort, inconsistency
		ret = 2;
	else if (cnt_max == 1) // there is always only one choice for find(next)
		ret = 1;
	else	// not determined
		ret = 0;

	return ret;
}

int
count(int next[])
{
	int	cnt, i;

	cnt = 0;
	for (i = 0; i < n; i++)
		if (next[i] == IN) cnt++;

	return cnt;
}

int
find(int next[])
{
	int	i;

	for (i = 0; i < n; i++)
		if (next[i] == IN)
			break;

	return i;	// note that i == n means there is no 'IN'
}
