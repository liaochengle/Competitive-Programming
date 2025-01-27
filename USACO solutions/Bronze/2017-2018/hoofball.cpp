#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int target(int i, vector<int>& x, int n)
{
	if (i == 0)
		return 1;
	else if (i == n - 1)
		return n - 2;
	else
	{
		int left_nbr = i - 1;
		int right_nbr = i + 1;
		if (x[i] - x[left_nbr] <= x[right_nbr] - x[i])
			return left_nbr;
		else
			return right_nbr;
	}
}

int hoofball()
{
	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	//ºÜÖØÒª£¡Ö»ÓÐÔÚÓÐÐòµÄÇé¿öÏÂ£¬targetÂß¼­²Å³ÉÁ¢
	sort(x.begin(), x.end());
	vector<int> passto(n, 0);
	for (int i = 0; i < n; i++)
	{
		passto[target(i, x, n)] += 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (passto[i] == 0)
			ans += 1;
		//µÚÒ»¸ö¶¨Ðò -> ²»»áËãÖØ¸´
		if (i < target(i, x, n) && target(target(i, x, n), x, n) == i && passto[i] == 1 && passto[target(i, x, n)] == 1)
			ans += 1;
	}
	cout << ans;
	return 0;
}
//ÖÕÓÚ£¡o ke k!
