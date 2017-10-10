#include <stdio.h>
#include <string.h>

#define MAXN 300 
#define SUCC 0
#define FAIL 1
#define AVAI 0
#define UNAV 1 
#define FREE 0
#define OCCU 1	// occupied

int n;
// solution saved, the number in the ith place means the ith-row queen in placed in the column with that number
int slt[MAXN + 1];	
// occupy state to record 'on the same columns' and 'on the same cross lines(two)'
int occ_col[MAXN],
    occ_x1[2 * MAXN - 1],
    occ_x2[2 * MAXN - 1];
int x1(int, int);
int x2(int, int);
int fill(int);	// fill the solution array in row's order
void solve();
void pr_solution();

int
main()
{
	while (scanf("%d", &n) && n != 0)
		solve();

	return 0;
}

void
solve()
{
	memset(occ_col, FREE, sizeof(occ_col));
	memset(occ_x1, FREE, sizeof(occ_x1));
	memset(occ_x2, FREE, sizeof(occ_x2));

	if (fill(1) != SUCC)
		printf("Unsolvable!\n");
	else
		pr_solution();

	return;
}

int
fill(int row)
{
	int	col;
	int	pre_col, pre_x1, pre_x2;

	if (row > n)
		return SUCC;

	for (col = 1; col <= n; col++) {
		if (occ_col[col] == FREE
			&& occ_x1[x1(row, col)] == FREE
			&& occ_x2[x2(row, col)] == FREE) {

			pre_col = occ_col[col];
			pre_x1 = occ_x1[x1(row, col)];
			pre_x2 = occ_x2[x2(row, col)];
			occ_col[col] = OCCU;
			occ_x1[x1(row, col)] = OCCU;
			occ_x2[x2(row, col)] = OCCU;

			if (fill(row + 1) == SUCC) {
				slt[row] = col;
				return SUCC;
			}

			occ_col[col] = pre_col; 
			occ_x1[x1(row, col)] = pre_x1; 
			occ_x2[x2(row, col)] = pre_x2;
		}
	}

	return FAIL;
}

int
x1(int row, int col)
{
	return n + col - row;	// (n - 1 + col) - (row - 1)
}

int
x2(int row, int col)
{
	return col + row - 1;	// col + (row - 1)
}

void
pr_solution()
{
	int	i;

	printf("%d", slt[1]);
	for (i = 2; i <= n; i++)
		printf(" %d", slt[i]);
	putchar('\n');

	return;
}
