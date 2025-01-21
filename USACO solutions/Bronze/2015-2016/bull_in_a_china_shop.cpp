#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

char original[8][8] ;
char piece[8][8];

void shift_up(char arr[8][8], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '#' && i == 0)
				return;
			if (arr[i][j] == '.')
				continue;
			arr[i - 1][j] = '#';
			arr[i][j] = '.';
		}
	}
}

void shift_down(char arr[8][8], int n)
{
	bool can_move_down = true;
	for (int i = 0; i < n; i++)
	{
		if (arr[n - 1][i] == '#')
		{
			can_move_down = false;
			break;
		}
	}
	if (can_move_down)
	{
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i + 1][j] = arr[i][j];
				if (i == 0)
					arr[i][j] = '.';
			}
		}
	}
}

void shift_right(char arr[8][8], int n)
{
	bool can_move_right = true;
	for (int i = 0; i < n; i++)
	{
		if (arr[i][n - 1] == '#')
		{
			can_move_right = false;
			break;
		}
	}
	if (can_move_right)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 2; j >= 0; j--)
			{
				arr[i][j + 1] = arr[i][j];
				if (j == 0)
					arr[i][j] = '.';
			}
		}
	}
}
void shift_left(char arr[8][8], int n)
{
	bool can_move_left = true;
	for (int i = 0; i < n; i++)
	{
		if (arr[i][0] == '#')
		{
			can_move_left = false;
			break;
		}
	}
	if (can_move_left)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				arr[i][j - 1] == arr[i][j];
				if (j == n - 1)
					arr[i][j] = '.';
			}
		}
	}
}

void printGrid(char arr[8][8], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << endl;
	}
}

void reset(char arr[8][8], int n)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			arr[i][j] = original[i][j];
	}
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> original[i][j];
	}
	reset(piece, 4);
	shift_down(piece, 4);
	printGrid(piece, 4);
	return 0;
}
