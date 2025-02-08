#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

bool average_pic(int i, int j, vector<int>& flowers)
{
	int sum = 0;
	for (int m = i; m <= j; m++)
		sum += flowers[m];
	if (sum % (j - i + 1) != 0)
		return false;
	int t = sum / (j - i + 1);
	for (int n = i; n <= j; n++)
	{
		if (flowers[n] == t)
		{
			return true;
		}
	}
	return false;
}

int daisy_chains()
{
	int n;
	cin >> n;
	vector<int> flowers(n);
	for (int i = 0; i < n; i++)
		cin >> flowers[i];
	
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (average_pic(i, j, flowers))
				answer += 1;
		}
	}
	cout << answer;
	return 0;
}
