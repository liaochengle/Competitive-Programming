#include <stdio.h>
#include <iostream>
using namespace std;

void pour(int a1, int& b1, int a2, int& b2)
{
	//m1 -> m2
	if (b1 + b2 <= a2)
	{
		b2 += b1;
		b1 = 0;
		return;
	}
	else if (b1 + b2 > a2)
	{
		b1 -= (a2 - b2);
		b2 = a2;
		return;
	}
}

int mixing_milk()
{
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);

	int c1, m1, c2, m2, c3, m3;
	cin >> c1 >> m1;
	cin >> c2 >> m2;
	cin >> c3 >> m3;

	for (int i = 0; i < 100; i++)
	{
		if ((i + 1) % 3 == 1)
			pour(c1, m1, c2, m2);
		else if ((i + 1) % 3 == 2)
			pour(c2, m2, c3, m3);
		else if ((i + 1) % 3 == 0)
			pour(c3, m3, c1, m1);
	}
	cout << m1 << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	return 0;
}

