#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void tipping(vector<vector<char>>& grid, int x, int y)
{
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			if (grid[i][j] == '0')
				grid[i][j] = '1';
			else if (grid[i][j] == '1')
				grid[i][j] = '0';
		}
	}
}

void printGrid(vector<vector<char>>& grid, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << grid[i][j];
		cout << endl;
	}
	cout << endl;
}

//wc!nb ÕâÕæÊÇ·ÖÎö³öÀ´µÄ£¡£¡£¡
int cow_tipping()
{
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<vector<char>> grid(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	int ans = 0;
	for (int i = 2*(n-1); i >= 0; --i)
	{
		int yMin = max(0, i - n + 1);
		int yMax = min(n - 1, i);
		for (int y = yMin; y <= yMax; ++y)
		{
			int x = i - y;
			if (grid[x][y] == '1')
			{
				//cout << x << y << endl;
				tipping(grid, x, y);
				//printGrid(grid, n);
				ans += 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

