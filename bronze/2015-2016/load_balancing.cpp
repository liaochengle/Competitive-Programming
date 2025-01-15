#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
	int x, y;
};

int load_balancing()
{
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	int N, B;
	scanf("%d %d", &N, &B);
	vector<point> points(N);
	int max_x = 0;
	int max_y = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &points[i].x, &points[i].y);
		max_x = max(max_x, points[i].x);
		max_y = max(max_y, points[i].y);
	}
		

	int ans = N;
	for (int i = 0; i < max_x; i += 2)
	{
		for (int j = 0; j < max_y; j += 2)
		{
			int a = 0, b = 0, c = 0, d = 0;
			for (int k = 0; k < N; k++)
			{
				int xt = points[k].x;
				int yt = points[k].y;
				if (xt < i && yt < j)
					a += 1;
				else if (xt < i && yt > j)
					b += 1;
				else if (xt > i && yt < j)
					c += 1;
				else if (xt > i && yt > j)
					d += 1;
			}
			int temp = max(max(a, b), max(c, d));
			ans = min(ans, temp);
		}
	}
	printf("%d", ans);
	return 0;
}
