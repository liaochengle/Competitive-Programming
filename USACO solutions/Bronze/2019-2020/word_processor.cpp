#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int word_processor()
{
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<string> words;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		words.push_back(word);
	}
	int count = 0;
	cout << words[0];
	count += words[0].size();
	for (int i = 1; i < n; i++)
	{
		if (count + words[i].size() <= k)
		{
			cout << " " << words[i];
			count += words[i].size();
		}
		else
		{
			count = 0;
			cout << "\n" << words[i];
			count += words[i].size();
		}
	}
	return 0;
}


