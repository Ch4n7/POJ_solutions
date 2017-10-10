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
	int	physi, emoti, inteli, date;
	int	d;

	scanf("%d%d%d%d", &physi, &emoti, &inteli, &date);
	caseno = 1;
	while (!((physi == END) && (emoti == END) && (inteli == END) && (date == END))) {
		for (d = date + 1; d <= date + MAXD; d++)
			if ((d - physi) % PHYSI == 0) break;
		for (; d <= date + MAXD; d += PHYSI)
			if ((d - emoti) % EMOTI == 0) break;
		for (; d <= date + MAXD; d += PHYSI * EMOTI)
			if ((d - inteli) % INTELI == 0) break;

		printf("Case %d: the next triple peak occurs in %d days.\n", caseno, d - date);

		scanf("%d%d%d%d", &physi, &emoti, &inteli, &date);
		caseno++;
	}

}
