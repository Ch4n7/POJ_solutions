#include <iostream>
#include <algorithm>

#define MAXN 407

using namespace std;

typedef struct {
	int	room;
	int	lr;	// 0 - left-end, 1 - right-end 
}mv;

bool comp(mv a, mv b)
{	
	return a.room < b.room;
}

mv movings[MAXN];

int
main()
{
	int	c, T, N, s, t, i,
		current, max ;
	cin >> T;
	for (c = 0; c < T; c++) {
		cin >> N;
		for (i = 0; i < N * 2; i += 2) {
			cin >> s >> t;
			if (s % 2 == 0) s--;// Unified into the north side
			if (t % 2 == 0) t--;// also unified
			if (s < t) {
				movings[i].room = s;
				movings[i].lr = 0;
				movings[i + 1].room = t;
				movings[i + 1].lr = 1;
			} else { // if t.room > s.room
				movings[i].room = t;
				movings[i].lr = 0;
				movings[i + 1].room = s;
				movings[i + 1].lr = 1;
			}
		}
		sort(movings, movings + N * 2, comp);
		// the max occupancy of one room is the anwser
		max = current = 0; 
		for (i = 0; i < N * 2; i ++) {
			if (movings[i].lr == 0) {
				current++;	
				if (current > max)
					max = current;
			} else
				current--;
		}
		cout << max * 10 << endl;
	}

	return 0;
}
