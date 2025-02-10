#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

int stuck_in_a_rut()
{
	int n;
	cin >> n;
	vector<vector<int>> E;
	vector<vector<int>> N;
	vector<pair<string, vector<int>>> cows(n);
	for (int i = 0; i < n; i++)
	{
		char d;
		int x, y;
		cin >> d >> x >> y;
		cows[i].first = d;
		cows[i].second = { x, y };
		if (d == 'E')
			E.push_back({ x, y, i });
		else if (d == 'N')
			N.push_back({ x, y, i });
	}
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		if (cows[i].first == "E")
		{
			bool flag = true;
			int time = 1000000;
			for (int j = 0; j < N.size(); j++)
			{
				if (ans[N[j][2]] == -1)
					continue;
				int et = N[j][0] - cows[i].second[0];
				int nt = cows[i].second[1] - N[j][1];
				if (et < 0 || nt < 0 || et == nt || et <= nt)
					continue;
				if (et > nt)
				{
					flag = false;
					//cout << cows[i].second[0] << " " << cows[i].second[1] << " " << N[j][0] << " " << N[j][1] << " " << et << " " << nt << endl;
					time = min(time, et);
				}
			}
			if (flag == true)
				ans[i] = -1;
			else
				ans[i] = time;
		}
		else
		{
			bool flag = true;
			int time = 1000000;
			for (int j = 0; j < E.size(); j++)
			{
				if (ans[E[j][2]] == -1)
					continue;
				int et = cows[i].second[0] - E[j][0];
				int nt = E[j][1] - cows[i].second[1];
				if (et < 0 || nt < 0 || et == nt || nt <= et)
					continue;
				if (nt > et)
				{
					flag = false;
					time = min(time, nt);
				}
			}
			if (flag == true)
				ans[i] = -1;
			else
				ans[i] = time;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == -1)
			cout << "Infinity" << endl;
		else
			cout << ans[i] << endl;
	}
	cout << endl;
	return 0;
}

