
#include <stdio.h>
#include <algorithm>
using namespace std;

int the_bucket_list()
{
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	int n;
	scanf("%d", &n);
	int time[1001] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int s, t, b;
		scanf("%d %d %d", &s, &t, &b);
		for (int j = s; j <= t; j++)
			time[j] += b;
	}
	int ans = 0;
	for (int i = 0; i < 1001; i++)
		ans = max(ans, time[i]);
	printf("%d", ans);
	return 0;
}
