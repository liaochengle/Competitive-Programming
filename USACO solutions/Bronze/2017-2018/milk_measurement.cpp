#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/std
using namespace std;

struct cow
{
	int date, change;
	string name;
};

bool cmp(cow a, cow b)
{
	return a.date < b.date;
}

int milk_measurement()
{
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	vector<int> cows(3);
	int n;
	scanf("%d", &n);
	vector<cow> data(n);
	for (int i = 0; i < n; i++)
	{
		cin >> data[i].date >> data[i].name >> data[i].change;
	}
	sort(data.begin(), data.end(), cmp);

	int ans = 0;
	vector<int> max_index;
	for (int i = 0; i < n; i++)
	{
		if (data[i].name == "Bessie")
			cows[0] += data[i].change;
		else if (data[i].name == "Elsie")
			cows[1] += data[i].change;
		else
			cows[2] += data[i].change;
		int temp_max = *max_element(cows.begin(), cows.end());
		vector<int> temp_index;
		for (int j = 0; j < 3; j++)
		{
			if (cows[j] == temp_max)
				temp_index.push_back(j);
		}
		if (max_index != temp_index)
		{
			ans += 1;
			max_index = temp_index;
		}
	}
	printf("%d", ans);
	return 0;
}
