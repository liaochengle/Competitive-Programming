#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int out_of_place()
{
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> o_arr(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &o_arr[i]);

	vector<int> s_arr = o_arr;
	sort(s_arr.begin(), s_arr.end());
	int dif = 0;
	for (int i = 0; i < n; i++)
	{
		if (s_arr[i] != o_arr[i])
			dif += 1;
	}
	printf("%d", dif - 1);
	return 0;
}
