#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

bool in_order(string& alphabet, string& heard, int start, int end)
{
	int index = -1;
	for (int i = start; i <= end; i++)
	{
		int temp = find(alphabet.begin(), alphabet.end(), heard[i]) - alphabet.begin();
		//cout << i << " " <<index << " " << temp << endl;
		if (temp <= index)
			return false;
		else if (temp > index)
			index = temp;
	}
	return true;
}

int uddered_but_not_herd()
{
	string alphabet;
	cin >> alphabet;
	string heard;
	cin >> heard;

	int answer = 0;
	for (int i = 0; i < heard.size(); i++)
	{
		int j = i;
		for (j; j < heard.size(); j++)
		{
			if (!in_order(alphabet, heard, i, j))
				break;
		}

		answer += 1;
		i = j - 1;
	}
	cout << answer;
	return 0;
}

