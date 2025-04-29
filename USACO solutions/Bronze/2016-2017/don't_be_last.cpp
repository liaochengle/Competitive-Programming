#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#
using namespace std;

int dont_be_last()
{
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

	vector<string> cows = { "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta" };
	vector<int> milks(7, 0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string name;
		int milk;
		cin >> name >> milk;
		int j = 0;
		for (j; j < 7; j++)
		{
			if (cows[j] == name)
				break;
		}
		milks[j] += milk;
	}

	int mins = *min_element(milks.begin(), milks.end());
	int second_min = 10000;
	for (int i = 0; i < 7; i++)
	{
		if (milks[i] == mins)
			continue;
		second_min = min(second_min, milks[i]);
	}

	int ans = count(milks.begin(), milks.end(), second_min);
	if (ans != 1)
		printf("Tie\n");
	else
	{
		for (int i = 0; i < 7; i++)
		{
			if (milks[i] == second_min)
			{
				cout << cows[i] << endl;
				break;
			}
		}
	}
	return 0;
}
