#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int herdle()
{
	vector<vector<char>> correct(3, vector<char>(3));
	vector<vector<char>> guess(3, vector<char>(3));
	set<char> breed1;
	set<char> breed2;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char c;
			cin >> c;
			breed1.insert(c);
			correct[i][j] = c;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char c;
			cin >> c;
			breed2.insert(c);
			guess[i][j] = c;
		}
	}

	int green = 0;
	int yellow = 0;
	for (set<char>::iterator it = breed2.begin(); it != breed2.end(); it++)
	{
		char b = *it;
		if (breed1.find(b) == breed1.end())
			continue;

		vector<int> xs;
		vector<int> ys;
		int num1 = 0;
		int num2 = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (guess[i][j] == b)
				{
					num2 += 1;
					xs.push_back(i);
					ys.push_back(j);
				}
				if (correct[i][j] == b)
				{
					num1 += 1;
				}
			}

		int num = min(num1, num2);
		for (int i = 0; i < xs.size(); i++)
		{
			int x = xs[i];
			int y = ys[i];
			if (correct[x][y] == b)
			{
				//cout << x << " " << y << " " << b << endl;
				green += 1;
				num -= 1;
			}
		}
		yellow += num;
	}
	cout << green << endl;
	cout << yellow << endl;
	return 0;
}

