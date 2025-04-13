#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#i
using namespace std;


bool spell(vector<string>& cubes, string word, vector<bool>& used, string ans, int index, string& answer, bool flag)
{
	if (ans == word && flag == false)
	{
		answer = "YES";
		flag = true;
		return true;
	}

	if (!flag)
	{
		for (int i = 0; i < 4; i++)
		{
			if (used[i] == true)
				continue;
			int num = count(cubes[i].begin(), cubes[i].end(), word[index]);
			if (num == 0)
				continue;
			ans.push_back(word[index]);
			used[i] = true;
			spell(cubes, word, used, ans, index + 1, answer, flag);
			ans.pop_back();
			used[i] = false;
		}
	}
	
}

int blocks()
{
	int n;
	cin >> n;
	vector<string> cubes(4);
	for (int i = 0; i < 4; i++)
	{
		string s;
		cin >> s;
		cubes[i] = s;
	}
	vector<string> words(n);
	for (int i = 0; i < n; i++)
		cin >> words[i];

	for (int i = 0; i < n; i++)
	{
		string ans;
		vector<bool> used(4, false);
		string answer = "NO";
		bool flag = false;
		bool valid = spell(cubes, words[i], used, ans, 0, answer, flag);
		cout << answer<< endl;
	}
	return 0;
}

