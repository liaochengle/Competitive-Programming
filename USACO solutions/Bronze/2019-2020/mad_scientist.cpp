#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mad_scientit()
{
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);

	int n;
	cin >> n;
	string line;
	string original;
	cin >> line;
	cin >> original;
	vector<int> index(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (line[i] != original[i])
			index[i] = 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (index[i] == 1)
		{
			while (i < n && index[i] == 1)
			{
				i++;
			}
			i -= 1;
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}

