#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <string.h>

#define MAXN 26

using namespace std;

list<int> adj_lists[MAXN];
int	n, m;
string	seq;
int	run();

int
main()
{
	int	r, i;
	char	rel[7]; 
	int	u, v;
	int	flag;

	while ((cin >> n >> m)
	   && !(m == 0 && n == 0)) {
		r = 0;
		flag = 0;
		for (i = 0; i < n; i++)
			adj_lists[i].clear();
		while (r < m) {
			cin >> rel, r++;
			u = rel[0] - 'A';
			v = rel[2] - 'A';
			adj_lists[u].push_back(v);
			switch (run()) {
				case 0:
					continue;
				case 1: 
					cout << "Sorted sequence determined after " << r << " relations: "
						<< seq << '.' << endl;
					flag = 1;
					break;
				case 2:
					cout << "Inconsistency found after " << r << " relations." << endl;
					flag = 1;
					break;
			}
			for (; r < m; r++) cin >> rel;
		}
		if (!flag)
			cout << "Sorted sequence cannot be determined." << endl;

	}

	return 0;
}

int
run()
{
	list<int> next;
	list<int>::iterator it;
	int	in_degree[MAXN];
	int	u, v;
	char	chu;
	int	ret;

	// in-degree[]
	memset(in_degree, 0, sizeof(in_degree));
	for (u = 0; u < n; u++) {
		it = adj_lists[u].begin();
		while (it != adj_lists[u].end()) {
			in_degree[*it]++;
			it++;
		}
	}
	// next
	for (u = 0; u < n; u++) {
		if (!in_degree[u])
			next.push_back(u);
	}
	seq.clear();
	ret = 1;	// default, determined
	while (!next.empty()) {
		if (next.size() > 1) ret = 0;	// unfortunately, not determined yet
		u = next.front();
		next.pop_front();
		chu = u + 'A';
		seq += chu;	// string append operator '+='
		for (it = adj_lists[u].begin(); it != adj_lists[u].end(); it++) {
			in_degree[*it]--;
			if (!in_degree[*it])
				next.push_back(*it);
		}
	}

	if (seq.size() != n)	// inconsitency
		ret = 2;

	return ret;

}
