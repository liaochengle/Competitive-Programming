#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int bucket_brigade()
{
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);

	char grid[10][10];
	int x[3];
	int y[3];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			char in;
			cin >> in;
			grid[i][j] = in;
			if (in == 'B')
			{
				x[0] = i;
				y[0] = j;
			}
			else if (in == 'L')
			{
				x[1] = i;
				y[1] = j;
			}
			else if (in == 'R')
			{
				x[2] = i;
				y[2] = j;
			}
		}
	}
	//B LÍ¬ÐÐ£¬RÔÚÆäÖÐ
	if (x[0] == x[1] && x[1] == x[2])
	{
		if ((y[0] < y[2] && y[2] < y[1]) || (y[1] < y[2] && y[2] < y[0]))
		{
			cout << abs(y[0] - y[1]) + 2 - 1;
			return 0;
		}
		else
		{
			cout << abs(y[0] - y[1]) - 1;
			return 0;
		}
	}
	if (y[0] == y[1] && y[1] == y[2])
	{
		if ((x[0] < x[2] && x[2] < x[1]) || (x[1] < x[2] && x[2] < x[0]))
		{
			cout << abs(x[0] - x[1]) + 2 - 1;
			return 0;
		}
		else
		{
			cout << abs(x[0] - x[1]) - 1;
			return 0;
		}
	}
	else
	{
		cout << abs(y[0] - y[1]) + abs(x[0] - x[1]) - 1;
		return 0;
	}
	return 0;
}
