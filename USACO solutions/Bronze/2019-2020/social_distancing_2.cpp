#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int cows[1000001] = { 0 };
int social_distancing()
{
	freopen("socdist2.in", "r", stdin);
	freopen("socdist2.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, s;
		cin >> p >> s;
		if (s == 1)
			cows[p] = 1;
		if (s == 0)
			cows[p] = -1;
	}
	int r = 1000000;
	int start = -1;
	for (int i = 0; i < 1000001; i++)
	{
		if (cows[i] != 0)
		{
			if (start != -1 && cows[start] != cows[i] && i - start < r)
				r = i - start;
			start = i;
		}
	}

	int ans = 0;
	int status = -1;
	for (int i = 0; i < 1000001; i++)
	{
		if (cows[i] != 0)
		{
			if (cows[i] != status && cows[i] == 1)
				ans += 1;
			status = cows[i];
		}
	}
	int start2 = 0;
	for (int i = 0; i < 1000001; i++)
	{
		if (cows[i] != 0)
		{
			if (start2 != 0 && cows[start2] == 1 && cows[i] == 1 && i - start2 >= r)
				ans += 1;
			start2 = i;
		}
	}
	cout << ans;
	return 0;
}


