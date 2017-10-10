#include <iostream>
#include <vector>
#include <string.h>

#define MAXN 128

using namespace std;

typedef struct {
	int u, v;
	double r, c;
} edge_t;

int	n, m, s;
double	v;
double most[MAXN];
vector<edge_t> edges;

void bellman_ford();
int  update(vector<edge_t>::iterator);
int  find_increasing_circle();

int
main()
{
	int	n1, n2;
	double	r12, c12, r21, c21;
	edge_t	tmp;

	// input
	cin >> n >> m >> s >> v;
	while (m--) {
		cin >> n1 >> n2;
		cin >> r12 >> c12 >> r21 >> c21;
		tmp.u = n1; tmp.v = n2; tmp.r = r12; tmp.c = c12;
		edges.push_back(tmp);
		tmp.u = n2; tmp.v = n1; tmp.r = r21; tmp.c = c21;
		edges.push_back(tmp);
	}
	// bellman-ford()-like
	bellman_ford();
	// judge on result
	if (find_increasing_circle())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

void
bellman_ford()
{
	int	i;
	vector<edge_t>::iterator it;

	memset(most, 0, sizeof(most));
	most[s] = v;
	for (i = 0; i < n - 1; i++)	// n - 1 times
		for (it = edges.begin(); it != edges.end(); it++)
			update(it);
}

int
find_increasing_circle()
{
	vector<edge_t>::iterator it;

	for (it = edges.begin(); it != edges.end(); it++)	// Anyway, circles must occur after n-th iteration
		if (update(it))
			return 1;	// 1 means FOUND

	return 0;	// 0 means NOT-FOUND
}

int
update(vector<edge_t>::iterator it_edge)
{
	int	u = (*it_edge).u, 
		v = (*it_edge).v;
	double	after_exch;
	double	curr, rate, coms;
	int	ret = 0;

	if (most[u] > 0) {	// must always have non-negative sum of money while making operations:w
		curr = most[u];
		rate = (*it_edge).r;
		coms = (*it_edge).c;
		after_exch = (curr - coms) * rate;
		if (after_exch > most[v]) {	// RELAX()-like
			most[v] = after_exch;
			ret = 1;
		}
	}

	return ret;	// 0 means do nothing, 1 means updated
}
