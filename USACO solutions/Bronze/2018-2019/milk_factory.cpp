#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void find_station(vector<int>& ans, vector<vector<int>>& factory, int num)
{
	if (factory[num].size() == 0)
		return;
	vector<int> nums = factory[num];
	for (int i = 0; i < nums.size(); i++)
	{
		ans.push_back(nums[i]);
		find_station(ans, factory, nums[i]);
	}
}

int milk_factory()
{
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

	int n;
	cin >> n;
	vector<vector<int>> factory(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		factory[b].push_back(a);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		vector<int> ans;
		find_station(ans, factory, i);
		if (ans.size() == n - 1)
		{
			answer = i;
			cout << answer;
			return 0;
		}
	}
	if (answer == 0)
		cout << -1;
	return 0;
}
