#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int angry_cows()
{
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> numbers(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	sort(numbers.begin(), numbers.end());
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int r = 1;
		int left = 0;
		int right = 0;
		for (int j = i; j >= 0; j--)
		{
			if (j == 0)
				break;
			if (numbers[j] - r > numbers[j - 1])
				break;
			int temp = j - 1;
			while (numbers[j] - r <= numbers[temp])
			{
				left += 1;
				temp -= 1;
				if (temp < 0)
					break;
			}
			j = temp + 1 + 1;
			r += 1;
		}
		r = 1;
		for (int j = i; j < n; j++)
		{
			if (j == n - 1)
				break;
			if (numbers[j] + r < numbers[j + 1])
				break;
			int temp = j + 1;
			while (numbers[j] + r >= numbers[temp])
			{
				right += 1;
				temp += 1;
				if (temp > n - 1)
					break;
			}
			j = temp - 1 - 1;
			r += 1;
		}
		//cout << i << left << right << endl;
		ans = max(ans, left + right + 1);
	}
	printf("%d", ans);
	return 0;
}