#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 1024
#define NIL -1
#define M 1024

typedef struct 
{
	int	x;
	int	y;
} point_t;
typedef int coord_t;

point_t points[MAXN];
int next[MAXN];
int hash_table[M];

int  h(point_t);
void hash_insert(int);

int
main()
{
	int	n, i, j, count;
	point_t	p3, p4;
	coord_t dx, dy;

	scanf("%d", &n);
	while(n) {
		// scanf 
		for (i = 0; i < n; i++) 
			scanf("%d %d", &points[i].x, &points[i].y);
		// build hash table
		memset(hash_table, NIL, sizeof(hash_table));
		memset(next, NIL, sizeof(next));
		for (i = 0; i < n; i++)
			hash_insert(i);
		// enumerate, construct squares and judge
		count = 0;
		for (i = 0; i < n - 1; i++)
			for (j = i + 1; j < n; j++) {
				dx = points[j].x - points[i].x;
				dy = points[j].y - points[i].y;
				// the square to right of p1->p2 
				p3.x = points[i].x + dy;
				p3.y = points[i].y - dx;
				p4.x = points[j].x + dy;
				p4.y = points[j].y - dx;
				if (hash_search(p3) >= 0 
				 && hash_search(p4) >= 0)
					count++;
				// the square to left of p1->p2
				p3.x = points[i].x - dy;
				p3.y = points[i].y + dx;
				p4.x = points[j].x - dy;
				p4.y = points[j].y + dx;
				if (hash_search(p3) >= 0
				 && hash_search(p4) >= 0)
					count++;
			}

		printf("%d\n", count / 4);
		scanf("%d", &n);
	}
}

int
h(point_t p)
{
	return abs(p.x + p.y) % M;
}

void
hash_insert(int i)
{
	int	key = h(points[i]);

	next[i] = hash_table[key];
	hash_table[key] = i;
}

int
hash_search(point_t p)
{
	int	key = h(p);
	int	i;

	i  = hash_table[key];
	while (i != NIL) {
		if (points[i].x == p.x && points[i].y == p.y)
			return	i;
		else
			i = next[i];
	}

	return NIL;
}
