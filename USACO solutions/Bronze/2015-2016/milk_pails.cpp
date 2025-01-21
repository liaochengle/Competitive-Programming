#include <stdio.h>
#include <algorithm>
using namespace std;

int milk_pails()
{
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	int x, y, m;
	scanf("%d %d %d", &x, &y, &m);
	int xn = int(m / x) + 1;
	int yn = int(m / y) + 1;
	int ans = 0;
	for (int i = 0; i < xn; i++)
	{
		for (int j = 0; j < yn; j++)
		{
			int temp = x * i + y * j;
			if (temp > m)
				continue;
			ans = max(ans, temp);
		}
	}
	printf("%d", ans);
	return 0;
}
