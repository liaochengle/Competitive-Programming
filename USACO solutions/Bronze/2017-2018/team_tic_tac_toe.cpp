#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int team_tic_tac_toe()
{
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);

	vector<vector<char>> grid(3, vector<char>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> grid[i][j];
	}

	set<char> onecow;
	set<set<char>> twocow;
	for (int i = 0; i < 3; i++)
	{
		//line
		set<char> line;
		for (int j = 0; j < 3; j++)
			line.insert(grid[i][j]);
		if (line.size() == 1)
			onecow.insert(*(line.begin()));
		else if (line.size() == 2)
		{
			twocow.insert(line);
		}
		//column
		set<char> column;
		for (int j = 0; j < 3; j++)
			column.insert(grid[j][i]);
		if (column.size() == 1)
			onecow.insert(*(column.begin()));
		else if (column.size() == 2)
		{
			twocow.insert(column);
		}
	}
	set<char> right;
	set<char> left;
	for (int i = 0; i < 3; i++)
	{
		right.insert(grid[i][i]);
		left.insert(grid[i][2 - i]);
	}
	if (right.size() == 1)
		onecow.insert(*(right.begin()));
	else if (right.size() == 2)
	{
		twocow.insert(right);
	}
	if (left.size() == 1)
		onecow.insert(*(left.begin()));
	else if (left.size() == 2)
	{
		twocow.insert(left);
	}
	cout << onecow.size() << endl;
	cout << twocow.size() << endl;
	return 0;
}

