#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bits/s
using namespace std;
void even(set<int>& f, vector<int>& a, vector<int>& b, int c, int d, int e);

void odd(set<int>& ans, vector<int>& bucket1, vector<int>& bucket2, int b1milk, int b2milk, int date)
{
	for (int i = 0; i < bucket2.size(); i++)
	{
		int x = bucket2[i];
		vector<int> new_bucket1 = bucket1;
		vector<int> new_bucket2 = bucket2;
		new_bucket1.push_back(x);
		new_bucket2.erase(new_bucket2.begin() + i);
		even(ans, new_bucket1, new_bucket2, b1milk + x, b2milk - x, date + 1);
	}

}

void even(set<int>& ans, vector<int>& bucket1, vector<int>& bucket2, int b1milk, int b2milk, int date)
{
	if (date == 6)
	{
		ans.insert(b1milk);
		return;
	}
	for (int i = 0; i < bucket1.size(); i++)
	{
		int x = bucket1[i];
		vector<int> new_bucket1 = bucket1;
		vector<int> new_bucket2 = bucket2;
		new_bucket2.push_back(x);
		new_bucket1.erase(new_bucket1.begin() + i);
		odd(ans, new_bucket1, new_bucket2, b1milk - x, b2milk + x, date + 1);
	}
}

int back_and_forth()
{
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

	int b1milk = 1000;
	int b2milk = 1000;
	vector<int> bucket1;
	vector<int> bucket2;
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		bucket1.push_back(num);
	}
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		bucket2.push_back(num);
	}

	set<int> ans;
	even(ans, bucket1, bucket2, b1milk, b2milk, 2);
	cout << ans.size();
	return 0;
}


