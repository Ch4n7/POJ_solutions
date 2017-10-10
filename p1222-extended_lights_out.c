#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 6

int puzzle[ROWS+2][COLS+2], press[ROWS+2][COLS+2];
int yes();	

int
main()
{
	int	n, p;
	int	r, c;
	int	i, j, tmp;

	memset(press, 0, sizeof(press));
	scanf("%d\n", &n);
	for (p = 1; p <= n; p++) {
		// readin 
		for (r = 1; r <= ROWS; r++)
			for (c = 1; c <= COLS; c++)
				scanf("%d", &puzzle[r][c]); 
		// enumeration and evolution
		for (i = 0; i < (1 << COLS); i++) {
			// enumerate the first row of press[]
			tmp = i;
			for (j = 1; j <= COLS; j++) {
				press[1][j] = tmp % 2;
				tmp  = tmp >> 1;
			}
			// evolution from row 1 to row 5 of press[]
			for (r = 2; r <= ROWS; r++)
				for (c = 1; c <= COLS; c++)
					press[r][c] = (puzzle[r-1][c] + 
							press[r-1][c] + 
							press[r-1][c-1] + press[r-1][c+1] +
							press[r-2][c]) % 2;
			// check if the 5th row also light out?
			if (yes()) {
				printf("PUZZLE #%d\n", p);
				for (r = 1; r <= ROWS; r++) {
					for (c = 1; c < COLS; c++)
						printf("%d ", press[r][c]);
					printf("%d\n", press[r][c]);
				}

			}
			else
				continue;
		}
	}
}

int
yes()
{
	int	c;

	for (c = 1; c <= COLS; c++)
		if ((puzzle[ROWS][c] + press[ROWS][c] + 
			press[ROWS][c-1] + press[ROWS][c+1] +
			press[ROWS-1][c]) % 2)
			return 0;

	return 1;
}
