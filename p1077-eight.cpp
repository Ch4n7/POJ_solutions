#include <iostream>
#include <queue>
#include <stack>
#include <string.h>

#define TILES 9
#define XSIGN 9	// note: 9 represents 'x' in the 'state_t'
#define FACTOR 362880	// factorial of 9(tiles)
#define GOAL 0	// my canto value is 0 of the goal state {1,2,3,4,5,6,7,8,9}
#define SUCCESS 1
#define FAILURE 0

using namespace std;
typedef struct {
	int state[TILES];
} state_t;

state_t puzzle;
int vis[FACTOR];
int pred[FACTOR];
int trans[FACTOR];
char dirs[4] = {'u', 'd', 'l', 'r'};

int run();
void pr_solution();
int find(state_t *, int);
int canto(state_t *);
void swap(state_t *, int, int);

int
main()
{
	int	i;
	char	ch;

	// readin
	for (i = 0; i < TILES; i++) {
		cin >> ch; 
		if (ch == 'x') 
			puzzle.state[i] = XSIGN;	
		else 
			puzzle.state[i] = ch - '0';
	}
	// procession and output
	if (run()) {
		pr_solution();
	} else {
		cout << "unsolvable" << endl;
	}

	return 0;
}

int
run()
{
	queue<state_t>	Q;
	state_t	cur, next;
	int	ccanv, ncanv;	// canto value; current_canv, next_canv
	int	x, y[4];	// y -> 4 directions' transition
	int	i, j;

	// breadth-first search
	Q.push(puzzle);	
	while (!Q.empty()) {
		// current state
		cur = Q.front();
		ccanv = canto(&cur);
		if (ccanv == GOAL)
			return SUCCESS;
		// extend
		x = find(&cur, XSIGN);
		y[0] = x - 3; // up			// 0 1 2
		y[1] = x + 3; // down			// 3 4 5
		if (x % 3 == 0) y[2] = -1; // left	// 6 7 8
		else y[2] = x - 1;
		if (x % 3 == 2)	y[3] = -1; // right
		else y[3] = x + 1;
		for (i = 0; i < 4; i++) {
			if (y[i] >= 0 && y[i] < 9) {
				next = cur;
				swap(&next, x, y[i]);
				ncanv = canto(&next);
				if (!vis[ncanv]) {
					Q.push(next);
					vis[ncanv] = 1;
					pred[ncanv] = ccanv;
					trans[ncanv] = i;
				}
			}
		}
		// pop current state
		Q.pop();
		vis[ccanv] = 1;
	}

	return FAILURE;
}

void
pr_solution()
{
	stack<int> S;
	int	canv, pcanv;
	int	t;

	canv = GOAL;
	pcanv = canto(&puzzle);
	while (canv != pcanv) {
		S.push(trans[canv]);
		canv = pred[canv];
	}
	while (!S.empty()) {
		t = S.top();
		cout << dirs[t];
		S.pop();
	}
	cout << endl;

	return;
}

int
find(state_t *s, int x)
{
	int	i;
	int	*st = s -> state;

	for (i = 0; i < TILES; i++)
		if (st[i] == x)
			return i;
	
	return -1;
}

int
canto(state_t *s)
{
	int	index, cnt;
	int	i, k;
	int	used[TILES + 1];
	int	*st = s -> state;

	memset(used, 0, sizeof(used));
	index = 0;
	for (i = 0; i < (TILES - 1); i++) {
		cnt = 0;
		for (k = 1; k < st[i]; k++)
			if (!used[k]) cnt++;
		index = (index + cnt) * (TILES - (i + 1));
		used[st[i]] = 1;
	}

	return index;
}

void
swap(state_t *s, int x, int y)
{
	int	tmp;
	int	*st = s -> state;

	tmp = st[x];
	st[x] = st[y];
	st[y] = tmp;

	return;
}
