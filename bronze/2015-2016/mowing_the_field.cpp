#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int grid[2002][2002] = { 0 };
int time1[2002][2002] = { 0 };

int mwoing_the_field()
{
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	int x = 1000;
	int y = 1000;
	int t = 0;
	grid[x][y] = 1;
	time1[x][y] = t;

	int n;
	scanf("%d", &n);
	int ans = 800000;
	for (int i = 0; i < n; i++)
	{
		char d;
		int s;
		cin >> d >> s;
		if (d == 'N')
		{
			for (int i = 0; i < s; i++)
			{
				x += 1;
				t += 1;
				if (grid[x][y])
					ans = min(ans, t - time1[x][y]);
				grid[x][y] = 1;
				time1[x][y] = t;
			}
		}
		else if (d == 'E')
		{
			for (int i = 0; i < s; i++)
			{
				y += 1;
				t += 1;
				if (grid[x][y])
					ans = min(ans, t - time1[x][y]);
				grid[x][y] = 1;
				time1[x][y] = t;
			}
		}
		else if (d == 'S')
		{
			for (int i = 0; i < s; i++)
			{
				x -= 1;
				t += 1;
				if (grid[x][y])
					ans = min(ans, t - time1[x][y]);
				grid[x][y] = 1;
				time1[x][y] = t;
			}
		}
		else if (d == 'W')
		{
			for (int i = 0; i < s; i++)
			{
				y -= 1;
				t += 1;
				if (grid[x][y])
					ans = min(ans, t - time1[x][y]);
				grid[x][y] = 1;
				time1[x][y] = t;
			}
		}
	}
	if (ans == 800000)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}
