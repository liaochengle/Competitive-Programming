#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool in_grid(int num, vector<vector<int>>& grid, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == num)
				return true;
		}
	}
	return false;
}

bool is_valid(int a, int b, vector<vector<int>>& grid, int n)
{
	int top = n, bottom = 0, left = n, right = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] != a)
				continue;
			top = min(top, i);
			bottom = max(bottom, i);
			left = min(left, j);
			right = max(right, j);
		}
	}
	for (int i = top; i <= bottom; i++)
	{
		for (int j = left; j <= right; j++)
		{
			if (grid[i][j] == b)
				return false;
		}
	}
	return true;
}

int main()
{
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);

	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char num;
			cin >> num;
			grid[i][j] = num - '0';
		}
	}

	int ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (!in_grid(i, grid, n))
			continue;
		bool first = true;
		for (int j = 1; j <= 9; j++)
		{
			if (i != j && in_grid(j, grid, n) && !is_valid(j, i, grid, n))
				first = false;
		}
		if (first)
			ans += 1;
	}
	printf("%d", ans);
	return 0;
}
