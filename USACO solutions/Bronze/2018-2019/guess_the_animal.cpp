#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct cow
{
	string name;
	vector<string> characters;
};

int compare(cow a, cow b)
{
	int ans = 0;
	vector<string> character1 = a.characters;
	vector<string> character2 = b.characters;
	for (int i = 0; i < character1.size(); i++)
	{
		if (find(character2.begin(), character2.end(), character1[i]) != character2.end())
			ans += 1;
	}
	return ans + 1;
}

int guess_the_animal()
{
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

	int n;
	cin >> n;
	vector<cow> cows(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cows[i].name;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			string character;
			cin >> character;
			cows[i].characters.push_back(character);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ans = max(ans, compare(cows[i], cows[j]));
		}
	}
	cout << ans;
	return 0;
}


