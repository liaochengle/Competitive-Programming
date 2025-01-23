#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool game(string c1, string c2, vector<string> rule)
{
	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < 3; i++)
	{
		if (rule[i] == c1)
			index1 = i;
		else if (rule[i] == c2)
			index2 = i;
	}
	if (index1 == 0 && index2 == 2)
		return false;
	if (index1 == 2 && index2 == 0)
		return true;
	if (index1 < index2)
		return true;
	return false;
}

int hoof_paper_scissors()
{
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<pair<int, int>> data(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &data[i].first, &data[i].second);

	vector<string> rule = { "hoof", "scissors", "paper" };

	vector<string> gesture = { "hoof", "paper", "scissors" };
	//vector<int> arr = { 0, 1, 2 };
	int ans = 0;
	do
	{
		int cow1 = 0;
		int cow2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (data[i].first == data[i].second)
				continue;
			else if (game(gesture[data[i].first - 1], gesture[data[i].second - 1], rule))
				cow1 += 1;
			else
				cow2 += 1;
		}
		ans = max(ans, max(cow1, cow2));
	} while (next_permutation(gesture.begin(), gesture.end()));

	printf("%d", ans);
	return 0;
}
