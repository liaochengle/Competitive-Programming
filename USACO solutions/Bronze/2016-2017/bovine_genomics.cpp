#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <bits/std
using namespace std;
//YAY!!!!!

struct letter
{
	char c;
	int num = 0;
};

int bovine_genomics()
{
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> spot(n, vector<char>(m));
	vector<vector<char>> nspot(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> spot[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> nspot[i][j];

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		set<char> c1;
		set<char> c2;
		for (int j = 0; j < n; j++)
		{
			c1.insert(spot[j][i]);
			c2.insert(nspot[j][i]);
		}

		bool valid = true;
		/*for (set<char> ::iterator it = c1.begin(); it != c1.end(); it++)
		{
			if (c2.find(*it) != c2.end())
			{
				valid = false;
				break;
			}
		}*/
		set<char> inter;
		set_intersection(c1.begin(), c1.end(), c2.begin(), c2.end(), inserter(inter, inter.begin()));
		if (inter.empty())
			ans += 1;
		
	}
	printf("%d", ans);
	return 0;
}
