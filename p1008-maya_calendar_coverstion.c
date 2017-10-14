#include <stdio.h>
#define H_MON_N 19
#define H_MON_L 8
#define T_DAY_N 20
#define T_DAY_L 10

char haab_months[H_MON_N][H_MON_L] = {"pop", "no", "zip", "zotz", "tzec",
	"xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin",
	"muan", "pax", "koyab", "cumhu", "uayet"},
     tzolkin_days[T_DAY_N][T_DAY_L] = { "imix", "ik", "akbal", "kan",
	     "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen",
	     "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", 
	     "ahau"};

int
main()
{
	int	n, i, j, d,
		day, mon, yr;
	char	str[8];

	scanf("%d", &n);
	printf("%d\n", n);
	for (i = 0; i < n; i++) {
		// notice input format
		scanf("%d.%s%d", &day, str, &yr);	
		for (j = 0; j < H_MON_N; j++)
			if (!strcmp(haab_months[j], str))
				mon = j;
		d = 365 * yr + 20 * mon + (day + 1);
		// Tzolkin
		yr = d / 260;
		d = d % 260; 
		if (!d) {d = 260; yr--;} // when d can be divied by 260, 
		mon = d % 13;	// it means it is last day of this year
		if (!mon) mon = 13;	// notice the special case when mod
		day = d % 20;	// leads to 0 whenever yr, mon or day!
		if (!day) day = 20;
		printf("%d %s %d\n", mon, tzolkin_days[day - 1], yr);
	}
	return 0;
}
