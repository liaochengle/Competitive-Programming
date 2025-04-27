#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#i
using namespace std;

int circular_barn()
{
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> rooms(2*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &rooms[i]);
		rooms[i + n] = rooms[i];
	}

	int ans = 1001 * 500 * 100;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = i + 1; j < i + n; j++)
		{
			temp += rooms[j] * abs(i - j);
		}
		ans = min(ans, temp);
	}
	printf("%d", ans);
	return 0;
}
