#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int diamond_collector()
{
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = 1;
		for (int j = i+1; j < n; j++)
		{
			if ((arr[j] - arr[i]) <= k)
				temp += 1;
		}
		ans = max(ans, temp);
	}
	printf("%d", ans);
	return 0;
}
