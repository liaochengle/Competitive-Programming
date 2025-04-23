#include <stdio.h>
#include <algorithm>
#include <vector>
#include <
using namespace std;

int lifeguards()
{
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> start(n);
	vector<int> end(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &start[i], &end[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		vector<int> time(1001, 0);
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			int st = start[j];
			int et = end[j];
			for (int k = st; k < et; k++)
				time[k] = 1;
		}
		int temp = count(time.begin(), time.end(), 1);
		ans = max(ans, temp);
	}
	printf("%d", ans);
	return 0;
}
