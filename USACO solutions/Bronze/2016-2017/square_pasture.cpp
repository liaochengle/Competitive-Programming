#include <stdio.h>
#include <algorithm>
#include <stdio.h>
#in
using namespace std;

struct point
{
	int x1, y1, x2, y2;
};

int square_pasture()
{
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	point points[2];
	for (int i = 0; i < 2; i++)
		scanf("%d %d %d %d", &points[i].x1, &points[i].y1, &points[i].x2, &points[i].y2);

	int x = max(points[0].x2, points[1].x2) - min(points[0].x1, points[1].x1);
	int y = max(points[0].y2, points[1].y2) - min(points[0].y1, points[1].y1);
	int side = max(x, y);
	printf("%d", side * side);
	return 0;
}
