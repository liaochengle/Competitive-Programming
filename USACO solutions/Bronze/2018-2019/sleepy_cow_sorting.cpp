#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int sleepy_cow_sorting()
{
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		if (arr[i] > arr[i + 1])
		{
			ans = i + 1;
			break;
		}
	}
	cout << ans;
	return 0;
}
