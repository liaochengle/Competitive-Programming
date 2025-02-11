#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if (a.first == b.first)
	return a.second < a.second;
    return a.first < b.first;
}

int acowdemia_3()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> pasture(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    cin >> pasture[i][j];
	}
    }
    int xi[] = { 1, 0, -1, 0 };
    int yi[] = { 0, 1, 0, -1 };
    int answer = 0;
    set<vector<pair<int, int>>> friends;
    for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < m; j++)
		{
		    if (pasture[i][j] != 'G')
			continue;
		    vector<pair<int, int>> cows;
		    for (int k = 0; k < 4; k++)
			{
			    int new_x = i + xi[k];
			    int new_y = j + yi[k];
			    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && pasture[new_x][new_y] == 'C')
				{
				    cows.push_back(pair<int, int>(new_x, new_y));
				}
			}
		    if (cows.size() < 2)
			continue;
		    if (cows.size() > 2)
			answer += 1;
		    else if (cows.size() == 2)
			{
			    sort(cows.begin(), cows.end(), cmp);
			    friends.insert(cows);
			}
		}
	}
    cout << answer + friends.size() << endl;
    return 0;
}

