#include <stdio.h>
#include <string.h>

#define COINS 12
#define NOTSURE 0
#define REAL 1
#define HEAVY 2
#define LIGHT 3

int	coins[COINS];
char	left[COINS + 1],
	right[COINS + 1];
char	balance[5];

int
main()
{
	int	n, l, i;
	char	*p, c;

	scanf("%d\n", &n);
	while (n--) {
		memset(coins, NOTSURE, sizeof(coins));
		for (l = 0; l < 3; l++) {
			scanf("%s %s %s\n", left, right, balance);
			switch (balance[0]) {
				case 'e':	// even
					for (p = left; (*p) != '\0'; p++)
						coins[(*p) - 'A'] = REAL;
					for (p = right; (*p) != '\0'; p++)
						coins[(*p) - 'A'] = REAL;
					break;
				case 'u':	// up
					for (i = 0; i < COINS; i++) {
						c = 'A' + i;
						if (strchr(left, c) != NULL) {
							if (coins[i] == NOTSURE)
								coins[i] = HEAVY;
							else if (coins[i] == LIGHT)	// inconsistency occurs
								coins[i] = REAL;	// it must be REAL
						} else if (strchr(right, c) != NULL) {
							if (coins[i] == NOTSURE)
								coins[i] = LIGHT;
							else if (coins[i] == HEAVY)	// inconsitency
								coins[i] = REAL;
						} else {
							coins[i] = REAL;
						}
					}
					break;
				case 'd':	// down
					for (i = 0; i < COINS; i++) {
						c = 'A' + i;
						if (strchr(left, c) != NULL) {
							if (coins[i] == NOTSURE)
								coins[i] = LIGHT;
							else if (coins[i] == HEAVY)	// inconsistency 
								coins[i] = REAL;	
						} else if (strchr(right, c) != NULL) {
							if (coins[i] == NOTSURE)
								coins[i] = HEAVY;
							else if (coins[i] == LIGHT)	// inconsitency
								coins[i] = REAL;
						} else {
							coins[i] = REAL;
						}
					}
			}
		}
		for (i = 0; i < COINS; i++)
			if (coins[i] != REAL) {
				c = 'A' + i;
				printf("%c is the counterfeit coin and it is %s.\n", c,
						coins[i] == HEAVY ? "heavy" : "light");
			}
	}
}
