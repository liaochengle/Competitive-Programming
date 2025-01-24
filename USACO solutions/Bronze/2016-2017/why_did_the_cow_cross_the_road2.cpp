#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct cow
{
	int x1 = -1, x2 = -1;
};

int cross_road2()
{
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	string s;
	cin >> s;
	vector<cow> cows(26);
	for (int i = 0; i < 52; i++)
	{
		int index = s[i] - 65;
		if (cows[index].x1 == -1)
			cows[index].x1 = i;
		else
			cows[index].x2 = i;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = i + 1; j < 26; j++)
		{
			int ix1 = cows[i].x1;
			int ix2 = cows[i].x2;
			int jx1 = cows[j].x1;
			int jx2 = cows[j].x2;
			if (ix2 < jx1 || jx2 < ix1)
				continue;
			else if (ix1 < jx1 && jx2 < ix2)
				continue;
			else if (jx1 < ix1 && ix2 < jx2)
				continue;
			//cout << i << " " << j << endl;
			ans += 1;
		}
	}
	printf("%d", ans);
	return 0;
}
