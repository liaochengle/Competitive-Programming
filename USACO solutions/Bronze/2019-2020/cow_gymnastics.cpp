#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <s
using namespace std;

bool is_consistent(int a, int b, vector<vector<int>>& stat, int k, int n)
{
	for (int i = 0; i < k; i++)
	{
		vector<int> temp = stat[i];
		int a1, b1;
		for (int j = 0; j < n; j++)
		{
			if (temp[j] == a)
				a1 = j;
			else if (temp[j] == b)
				b1 = j;
		}
		if (a1 < b1)
			return false;
	}
	return true;
}

int cow_gymnastics()
{
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int k, n;
	cin >> k >> n;
	vector<vector<int>> stat(k, vector<int>(n));
	for (int i = 0; i < k; i++)
	{
		vector<int> temp;
		for (int j = 0; j < n; j++)
			cin >> stat[i][j];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			if (is_consistent(i, j, stat, k, n))
				ans += 1;
		}
	}
	cout << ans;
	return 0;
}
