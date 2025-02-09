#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int just_stalling()
{
	int n;
	cin >> n;
	vector<long long> cows(n);
	vector<long long> stalls(n);
	for (int i = 0; i < n; i++)
		cin >> cows[i];
	for (int i = 0; i < n; i++)
		cin >> stalls[i];

	sort(cows.begin(), cows.end());
	sort(stalls.begin(), stalls.end());
	long long ans = 1;
	for (int s = 0; s < n; s++)
	{
		int count = 0;
		for (int c = 0; c < n; c++) {
			if (cows[c] <= stalls[s])
				count += 1;
		}
		count = max(0, count - s);
		ans *= count;
	}
	cout << ans << endl;
	return 0;
}

