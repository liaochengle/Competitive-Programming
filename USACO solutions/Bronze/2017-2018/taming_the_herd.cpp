#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int taming_the_herd()
{
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> counter(n, -1);
	counter[0] = 0;
	//vector<int> data(n);
	for (int i = 0; i < n; i++)
	{
		int log;
		scanf("%d", &log);
		if (log == -1)
			continue;
		else
		{
			int num = log;
			for (int j = i; j >= i - log; j--)
			{
				if (j < 0 || log <= -1)
					break;
				if (counter[j] != -1 && counter[j] != num)
				{
					cout << -1;
					return 0;
				}
				counter[j] = num;
				num -= 1;
			}
		}
	}
	int basic = count(counter.begin(), counter.end(), 0);
	int more = count(counter.begin(), counter.end(), -1);
	printf("%d %d", basic, basic + more);
	return 0;
}
