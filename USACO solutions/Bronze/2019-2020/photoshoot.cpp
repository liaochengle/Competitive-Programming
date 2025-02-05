#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

bool valid_arr(int start, vector<int>& nums, vector<int>& ans, int n)
{
	set<int> ori;
	for (int i = 1; i <= n; i++)
		ori.insert(i);

	set<int> temp;
	temp.insert(start);
	int before = start;
	for (int i = 1; i < n; i++)
	{
		ans[i] = nums[i - 1] - before;
		temp.insert(ans[i]);
		before = ans[i];
	}
	if (temp != ori)
		return false;
	return true;
}

int photoshoot()
{
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> nums(n - 1);
	for (int i = 0; i < n - 1; i++)
		cin >> nums[i];
	for (int start = 1; start < nums[0]; start++)
	{	
		vector<int> ans(n, 0);
		ans[0] = start;
		if (valid_arr(start, nums, ans, n))
		{
			for (int i = 0; i < n-1; i++)
				cout << ans[i] << " ";
			cout << ans[n - 1];
		}
	}
	return 0;
}
