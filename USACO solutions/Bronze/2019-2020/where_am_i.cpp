#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool no_same_subset(int length, string& mailbox, int k)
{
	set<string> unique;
	vector<string> subset;
	for (int i = 0; i < k - length + 1; i++)
	{
		string t = mailbox.substr(i, length);
		subset.push_back(t);
		unique.insert(t);
	}
	if (subset.size() != unique.size())
		return false;
	return true;
}

int where_am_i()
{
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);

	int k;
	cin >> k;
	string mailbox;
	cin >> mailbox;
	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		vector<string> subset;
		if (no_same_subset(i, mailbox, k))
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}

