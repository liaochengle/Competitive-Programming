#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int teleportation()
{
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);

	int a, b, x, y;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &x, &y);
	if (a >= b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	if (x>= y)
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	int ans = b - a;
	int temp = abs(a - x) + abs(b - y);
	ans = min(ans, temp);
	printf("%d", ans);
	return 0;
}

