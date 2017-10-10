#include <stdio.h>

#define MAXN 1024
#define NOTFOUND -1

typedef struct 
{
	int	x;
	int	y;
} point_t;
typedef int coord_t;

point_t points[MAXN];
void insertion_sort(point_t *, int);
int binary_search(point_t *, int, int, point_t);

int
main()
{
	int	n, i, j, count;
	int	x, y;
	point_t	p3, p4;
	coord_t dx, dy;

	scanf("%d", &n);
	while(n) {
		// scanf 
		for (i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			points[i].x = x;
			points[i].y = y;
		}
		// insertion sort, if x1 == x2, compare y1 with y2
		insertion_sort(points, n);
		// enumerate, construct squares and judge
		count = 0;
		for (i = 0; i < n - 1; i++)
			for (j = i + 1; j < n; j++) {
				dx = points[j].x - points[i].x;
				dy = points[j].y - points[i].y;
				// right square to p1->p2
				p3.x = points[i].x + dy;
				p3.y = points[i].y - dx;
				p4.x = points[j].x + dy;
				p4.y = points[j].y - dx;
				if (binary_search(points, j + 1, n - 1, p3) >= 0 
				 && binary_search(points, j + 1, n - 1, p4) >= 0) {
					count++;
					continue;
				}
				// left square to p1->p2
				p3.x = points[i].x - dy;
				p3.y = points[i].y + dx;
				p4.x = points[j].x - dy;
				p4.y = points[j].y + dx;
				if (binary_search(points, j + 1, n - 1, p3) >= 0
			         && binary_search(points, j + 1, n - 1, p4) >= 0) count++;
			}

		printf("%d\n", count);
		scanf("%d", &n);
	}
}

void
insertion_sort(point_t A[], int n)
{
	int	i, j;
	point_t	key;

	for (i = 1; i < n; i++) {
		key = A[i];
		j = i - 1;
		while (j >= 0 && (A[j].x > key.x || A[j].x == key.x && A[j].y > key.y)) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

int
binary_search(point_t A[], int p, int r, point_t x)
{
	int	q;

	while (p <= r) {
		q = (p + r) / 2;
		if (A[q].x == x.x && A[q].y == x.y)
			return q;
		else if (A[q].x > x.x || A[q].x == x.x && A[q].y > x.y)
			r = q - 1;
		else
			p = q + 1;
	}

	return NOTFOUND;

}
