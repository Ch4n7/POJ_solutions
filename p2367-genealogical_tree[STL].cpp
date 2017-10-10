#include <iostream>
#include <stack>
#include <list>
#include <string.h>

#define MAXN 101

using namespace std;

int
main()
{
	int	indegrees[MAXN];
	int	n, i, v;
	list<int> adj_list[MAXN];
	list<int>::iterator it;
	stack<int> next;

	memset(indegrees, 0, sizeof(indegrees));
	cin >> n;
	for (i = 1; i <= n; i++)
		while ((cin >> v) && (v != 0)) {
			adj_list[i].push_back(v);
			indegrees[v]++;
		}
	for (i = 1; i <= n; i++)
		if (indegrees[i] == 0)
			next.push(i);	
	i = 0;
	while (!next.empty()) {
		v = next.top();
		next.pop();
		cout << v;
		i++;
		if (i == n)
			cout << endl;
		else
			cout << ' ';
		for (it = adj_list[v].begin(); it != adj_list[v].end(); it++) {
			indegrees[*it]--;
			if (indegrees[*it] == 0)
				next.push(*it);
		}

	}

	return 0;
}
