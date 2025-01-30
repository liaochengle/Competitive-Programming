#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int milking_order()
{
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> hierarchy(m);
	for (int i = 0; i < m; i++)
		cin >> hierarchy[i];
	map<int, int> position;
	for (int i = 0; i < k; i++)
	{
		int num, index;
		cin >> num >> index;
		position.insert(pair<int, int>(num, index));
	}

	vector<int> arr;
	for (int i = 1; i <= n; i++)
		arr.push_back(i);

	int ans = n;
	do
	{
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (position.find(arr[i]) != position.end())
			{
				if (position[arr[i]] - 1 != i)
				{
					flag = false;
					break;
				}
			}
		}
		vector<int> temp_hierarchy;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i] == hierarchy[j])
				{
					temp_hierarchy.push_back(arr[i]);
					break;
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			if (hierarchy[i] != temp_hierarchy[i])
				flag = false;
		}
		if (flag)
		{
			int index = find(arr.begin(), arr.end(), 1) - arr.begin();
			ans = min(ans, index);
		}
	} while (next_permutation(arr.begin(), arr.end()));
	cout << ans + 1 << endl;
	return 0;
}

