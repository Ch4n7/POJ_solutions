#include <iostream>
#include <stack>

using namespace std;

typedef struct {
	int	left;
	int	right;
}lr;

int
main()
{
	int	i, j, t, n,
		pre, cur;
	lr	temp;
	stack<lr> S;

	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n;
		pre = 0;
		for (j = 0; j < n; j++) {
			cin >> cur;

			temp.left = cur - pre;
			temp.right = 0;
			if (temp.left != 0) S.push(temp);

			S.top().left--;
			S.top().right++;
			temp = S.top();
			cout << temp.right << ' ';
			if (temp.left == 0) {
				S.pop();
				if (S.size() != 0)
					S.top().right += temp.right;
			}

			pre = cur;
		}
		cout << endl;
	}		
}	
