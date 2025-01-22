#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int field_reduction()
{
	freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	int minx = min_element(x.begin(), x.end()) - x.begin();
	int maxx = max_element(x.begin(), x.end()) - x.begin();
	int miny = min_element(y.begin(), y.end()) - y.begin();
	int maxy = max_element(y.begin(), y.end()) - y.begin();
	int ans = 40000 * 40000;
	for (int i = 0; i < n; i++)
	{
		if (i != minx && i != maxx && i != miny && i != maxy)
			continue;
		int x1 = 40000;
		int x2 = 0;
		int y1 = 40000;
		int y2 = 0;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			x1 = min(x1, x[j]);
			x2 = max(x2, x[j]);
			y1 = min(y1, y[j]);
			y2 = max(y2, y[j]);
		}
		ans = min(ans, (x2 - x1) * (y2 - y1));
	}
	printf("%d", ans);
	return 0;
}
