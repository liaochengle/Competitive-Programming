#include <iostream>
using namespace std;

int oucc()
{
	int n;
	cin >> n;
	int stat[10];
	for (int i = 0; i < n; i++)
		cin >> stat[i];
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (stat[i + 1] > stat[i])
			ans += 1;
	}
	cout << ans * 100;
	return 0;
}
