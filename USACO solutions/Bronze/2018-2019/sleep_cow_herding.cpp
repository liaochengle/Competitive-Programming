#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;


int sleepy_cow_herding()
{
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	int num[3];
	for (int i = 0; i < 3; i++)
		cin >> num[i];
	sort(num, num + 3);
	int d1, d2;
	d1 = num[1] - num[0] - 1;
	d2 = num[2] - num[1] - 1;

	if (d1 == 0 && d2 == 0)
	{
		cout << 0 << endl;
		cout << 0 << endl;
		return 0;
	}
	if (d1 == 1 || d2 == 1)
	{
		cout << 1 << endl;
		cout << max(d1, d2) << endl;
		return 0;
	}
	else
	{
		cout << 2 << endl;
		cout << max(d1, d2);
	}
	return 0;
}

