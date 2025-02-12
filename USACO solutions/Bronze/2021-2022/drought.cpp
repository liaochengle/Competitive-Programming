#include <bits/stdc++.h>
using namespace std;


int corns(vector<int>& cows, int n)
{
	if (n == 1)
		return 0;
	if (n == 2 && cows[0] == cows[1])
		return 0;
	if (n == 2)
		return -1;
		
	int answer = 0;
	bool flag = false;
	for (int a0 = 0; a0 <= cows[0]; a0++)
	{
		flag = true;
		vector<int> a(n - 1);
		a[0] = a0;
		a[1] = cows[1] - cows[0];
		if (a[1] < 0)
			flag = false;
		for (int i = 2; i < n - 1; i++)
		{
			a[i] = cows[i] - cows[i - 1] + a[i - 2];
			if (a[i] < 0)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;
		if (cows[n - 1] - a[n - 2] != cows[0] - a[0])
		{
			flag = false;
		}
		if (flag)
		{
			//cout << "a1" << a[0] << endl;
			for (int i = 0; i < n - 1; i++)
				answer += a[i];
			return answer * 2;
		}
	}
	if (!flag)
		return -1;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		vector<int> cows(n);
		for (int i = 0; i < n; i++)
			cin >> cows[i];
		vector<int> same(n, cows[0]);
		if (cows == same)
			cout << 0 << endl;
		else
			cout << corns(cows, n) << endl;
			//cout << "ans" << corns(cows, n) << endl;
	}
	return 0;
}
