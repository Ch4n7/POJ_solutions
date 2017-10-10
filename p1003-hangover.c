#include <stdio.h>
#define MAXN 512	
// up to 5.2, it needs about 273+ cards from the input cases 5.19.
// Here, it has no harm to set MAXN 300, or 512. Big enough.

int
main()
{
	float	c, cards_len[MAXN];
	int	i;

	// cards_len[i] to record the result of "1/2 + 1/3 + .. + 1/(i+2)"
	// cards_len[] avoid repeated computations
	cards_len[0] = 0.5f;
	for (i = 1; i < MAXN; i++)
		cards_len[i] = cards_len[i - 1] + 1.0f/(float)(i + 2);
	while (scanf("%f", &c) == 1 && c != 0.0f) {
		for (i = 0; cards_len[i] < c; i++);// linear search
		printf("%d card(s)\n", i + 1);	// can also use binary search
	}

	return 0;
}
