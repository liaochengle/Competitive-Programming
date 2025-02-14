#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

void in_order(vector<int>& ori, vector<int>& arr, vector<int>& ans, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int i_ind = find(arr.begin(), arr.end(), ori[i]) - arr.begin();
			int j_ind = find(arr.begin(), arr.end(), ori[j]) - arr.begin();
			//cout << i << " " << j << " " << i_ind << " " << j_ind << endl;
			if (i_ind > j_ind)
				ans[j] = 1;
		}
	}
}

int photoshoot_2()
{
	int n;
	cin >> n;
	vector<int> ori(n);
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> ori[i];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> ans(n, 0);
	in_order(ori, arr, ans, n);
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer += ans[i];
	}
	cout << answer << endl;
	return 0;
}

