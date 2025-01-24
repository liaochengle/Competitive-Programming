#include <stdio.h>
#include <vector>
using namespace std;

int cross_the_road()
{
	freopen("crossroad.in", "r", stdin);
	freopen("crossroad.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<pair<int, int>> records(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &records[i].first, &records[i].second);
	}
	int ans = 0;
	vector<int> cows(11, -1);
	for (int i = 0; i < n; i++)
	{
		int index = records[i].first;
		int pos = records[i].second;
		if (cows[index] == -1)
		{
			cows[index] = pos;
			continue;
		}
		if (cows[index] != pos)
		{
			ans += 1;
			cows[index] = pos;
		}
	}
	printf("%d", ans);
	return 0;
}
