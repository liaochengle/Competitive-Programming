#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#in
using namespace std;

bool is_valid(vector<string>& cows, vector<string>& cows1, vector<string>& cows2, int n)
{
	for (int i = 0; i < n; i++)
	{
		int ind1 = find(cows.begin(), cows.end(), cows1[i]) - cows.begin();
		int ind2 = find(cows.begin(), cows.end(), cows2[i]) - cows.begin();
		if (abs(ind1 - ind2) != 1)
			return false;
	}
	return true;
}

int livestock_lineup()
{
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

	int n;
	cin >> n;
	vector<string> cows1;
	vector<string> cows2;
	for (int i = 0; i < n; i++)
	{
		vector<string> words(6);
		cin >> words[0];
		cin >> words[1];
		cin >> words[2];
		cin >> words[3];
		cin >> words[4];
		cin >> words[5];
		cows1.push_back(words[0]);
		cows2.push_back(words[5]);
	}
	vector<string> cows = { "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue" };
	sort(cows.begin(), cows.end());
	do
	{
		if (is_valid(cows, cows1, cows2, n))
			break;
	} while (next_permutation(cows.begin(), cows.end()));
	for (int i = 0; i < 8; i++)
		cout << cows[i] << endl;
	return 0;
}
