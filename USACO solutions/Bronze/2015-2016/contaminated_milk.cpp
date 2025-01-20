#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int contaminated_milk()
{
	freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);

	int n, ms, d, s;
	cin >> n >> ms >> d >> s;
	vector<vector<pair<int, int>>> data(n+1);
	vector<vector<int>> nums(n+1);
	for (int i = 0; i < d; i++)
	{
		int p, m, t;
		cin >> p >> m >> t;
		data[p].push_back(pair<int, int>(t, m));
		nums[p].push_back(m);
	}
	for (int i = 1; i < n + 1; i++)
	{
		sort(data[i].begin(), data[i].end());
	}
	vector<int> sickcow(ms + 1, 0);
	for (int i = 0; i < s; i++)
	{
		int p, t;
		cin >> p >> t;
		set<int> appeared;
		for (int j = 0; j < data[p].size(); j++)
		{
			if (data[p][j].first >= t)
				break;
			appeared.insert(data[p][j].second);
		}
		for (set<int>::iterator it = appeared.begin(); it != appeared.end(); it++)
			sickcow[*it] += 1;
	}
	vector<int> possiblecow;
	for (int i = 1; i < ms + 1; i++)
	{
		if (sickcow[i] == s)
			possiblecow.push_back(i);
	}
	//for (int i = 0; i < possiblecow.size(); i++)
		//cout << possiblecow[i] << " ";
	//cout << endl;
	
	int ans = 0;
	for (int i = 0; i < possiblecow.size(); i++)
	{
		int temp = 0;
		for (int j = 1; j < n + 1; j++)
		{
			if (count(nums[j].begin(), nums[j].end(), possiblecow[i]))
				temp += 1;
		}
		ans = max(temp, ans);
	}
	printf("%d", ans);
	return 0;
}
