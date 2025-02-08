#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int cells[1001][1001] = { 0 };
bool cows[1001][1001] = { false };
int comfortable_cows()
{
	int n;
	cin >> n;
	int xi[] = { 0, 1, 0, -1 };
	int yi[] = { 1, 0, -1, 0 };
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		cows[x][y] = true;
		for (int j = 0; j < 4; j++)
		{
			int new_x = x + xi[j];
			int new_y = y + yi[j];
			if (new_x >= 0 && new_x < 1001 && new_y >= 0 && new_y < 1001)
				cells[new_x][new_y] += 1;
			if (cells[new_x][new_y] == 3 && cows[new_x][new_y])
				ans += 1;
			if (cells[new_x][new_y] == 4 && cows[new_x][new_y])
				ans -= 1;
		}
		cout << ans << endl;
	}
	return 0;
}
