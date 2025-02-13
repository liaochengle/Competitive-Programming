#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int lonely_photo()
{
	int n;
	cin >> n;
	vector<char> cows(n);
	for (int i = 0; i < n; i++)
		cin >> cows[i];
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int g = 0;
		int h = 0;
		for (int j = i; j < n; j++)
		{
			if (cows[j] == 'G')
				g += 1;
			else
				h += 1;
			if (((g + h) >= 3) && (g == 1 || h == 1))
				ans += 1;
		}
	}
	cout << ans;
	return 0;
}


