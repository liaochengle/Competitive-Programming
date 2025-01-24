#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct cow
{
	int t, d;
};

bool cmp(cow a, cow b)
{
	if (a.t == b.t)
		return a.d < b.d;
	return a.t < b.t;
}

int cross_road3()
{
	freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<cow> cows(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &cows[i].t, &cows[i].d);
	}
	sort(cows.begin(), cows.end(), cmp);
	int ans = cows[0].t;
	for (int i = 0; i < n; i++)
	{
		ans += cows[i].d;
		if (i < (n - 1))
		{
			if (ans < cows[i + 1].t)
				ans = cows[i + 1].t;
		}
	}
	printf("%d", ans);
	return 0;
}
