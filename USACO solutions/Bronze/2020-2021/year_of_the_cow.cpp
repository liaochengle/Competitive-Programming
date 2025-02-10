#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<map>
#include <math.h>
#include <algorithm>
using namespace std;

int year_of_the_cow()
{
	vector<string> zodia = { "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig" };
	int n;
	cin >> n;
	//µÚÒ»¸öint -> year, µÚ¶þ¸ö ani
	map<string, pair<int, int>> cows;
	cows["Bessie"] = { 1, 1 };
	string cowa, born, in, time, ani, year, from, cowb;
	for (int i = 0; i < n; i++)
	{
		cin >> cowa >> born >> in >> time >> ani >> year >> from >> cowb;
		int ani_in = find(zodia.begin(), zodia.end(), ani) - zodia.begin();
		int new_ani = ani_in - cows[cowb].second;
		if (time == "previous")
		{
			if (new_ani >= 0)
			{
				new_ani -= 12;
			}
		}
		else if (time == "next")
		{
			if (new_ani <= 0)
				new_ani += 12;
		}
		int year = cows[cowb].first + new_ani;
		cows[cowa] = { year, ani_in };
		//cout << cowa << " " << new_ani << " " << year << " " << ani << endl;
		if (cowa == "Elsie")
			break;

	}
	cout << abs(cows["Bessie"].first - cows["Elsie"].first);
	return 0;
}

