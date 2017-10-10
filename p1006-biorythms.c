#include <stdio.h>

#define END -1 
#define PHYSI 23
#define EMOTI 28
#define INTELI 33
#define MAXD 21252

int
main()
{
	int	caseno;
	int	physi, emoti, inteli;
	int	date, d;
	int	start;

	scanf("%d%d%d%d", &physi, &emoti, &inteli, &date);
	caseno = 1;
	while (!((physi == END) && (emoti == END) && (inteli == END) && (date == END))) {
		start = date - inteli;
		if (start >= 0) {
			start = ((start / INTELI) + 1) * INTELI + inteli;
		} else if (start % INTELI) {
			start = (start / INTELI) * INTELI + inteli;
		} else {
			start = date + INTELI;
		}

		for (d = start; d <= date + MAXD; d += INTELI)
			if (((d - physi) % PHYSI == 0) && ((d - emoti) % EMOTI == 0)) break;

		printf("Case %d: the next triple peak occurs in %d days.\n", caseno, d - date);

		scanf("%d%d%d%d", &physi, &emoti, &inteli, &date);
		caseno++;
	}

}
