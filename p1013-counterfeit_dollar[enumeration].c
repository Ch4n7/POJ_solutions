#include <stdio.h>
#include <string.h>

#define COINSLEN 12
#define RESULTLEN 4
#define TIMES 3

char left[TIMES][COINSLEN + 1],
     right[TIMES][COINSLEN + 1];
char balance[TIMES][RESULTLEN + 1]; 

int is_heavy(char);
int is_light(char);

int
main()
{
	int	n, i;
	char	ch;
	
	scanf("%d\n", &n);
	while (n--) {
		for (i = 0; i < TIMES; i++)
			scanf("%s%s%s", left[i], right[i], balance[i]);
		for (ch = 'A'; ch <= 'L'; ch++) {
			if (is_heavy(ch)) {
				printf("%c is the counterfeit coin and it is heavy.\n", ch);
				break;
			}
			if (is_light(ch)) {
				printf("%c is the counterfeit coin and it is light.\n", ch);
				break;
			}
		}
	}
}

int
is_heavy(char x)
{
	int	i;

	for (i = 0; i < TIMES; i++) {
		switch (balance[i][0]) {
			case 'e':
				if (strchr(left[i], x) != NULL || 
						strchr(right[i], x) != NULL)
					return 0;
				break;
			case 'u':
				if (strchr(left[i], x) == NULL)
					return 0;
				break;
			case 'd':
				if (strchr(right[i], x) == NULL)
					return 0;
		}
	}

	return 1;
}

int
is_light(char x)
{
	int	i;

	for (i = 0; i < TIMES; i++) {
		switch (balance[i][0]) {
			case 'e':
				if (strchr(left[i], x) != NULL || 
						strchr(right[i], x) != NULL)
					return 0;
				break;
			case 'u':
				if (strchr(right[i], x) == NULL)
					return 0;
				break;
			case 'd':
				if (strchr(left[i], x) == NULL)
					return 0;
		}
	}

	return 1;
}
