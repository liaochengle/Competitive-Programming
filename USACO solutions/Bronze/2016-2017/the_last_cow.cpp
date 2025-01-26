#include <stdio.h>
#include <iostream>
using namespace std;

int the_lost_cow()
{
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

	int x, y;
	scanf("%d %d", &x, &y);
	int index = x;
	int dis = 1;
	int ans = 0;

	while (index != y)
	{
		if (dis > 0)
		{
			for (index; index < x + dis; index++)
			{
				if (index == y)
				{
					printf("%d", ans);
					return 0;
				}
				ans += 1;
			}
			dis *= -2;
		}
		if (dis < 0)
		{
			for (index; index > x + dis; index--)
			{
				if (index == y)
				{
					printf("%d", ans);
					return 0;
				}
				ans += 1;
			}
			dis *= -2;
		}
	}
	printf("%d", ans);
	return 0;
}
