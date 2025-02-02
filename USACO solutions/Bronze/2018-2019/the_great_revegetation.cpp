#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int the_great_revegetation()
{
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> cows(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		cows[a - 1].push_back(b - 1);
	}

	vector<int> pastures(n, 0);
	pastures[0] = 1;
	for (int i = 1; i < n; i++)
	{
		vector<int> appear;
		for (int j = 0; j < cows[i].size(); j++)
		{
			appear.push_back(pastures[cows[i][j]]);
		}
		for (int j = 1; j <= 4; j++)
		{
			if (find(appear.begin(), appear.end(), j) == appear.end())
			{
				pastures[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << pastures[i];
	return 0;
}
