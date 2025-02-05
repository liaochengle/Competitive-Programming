#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int min_time(int k, int x)
{
	int answer = 0;
	int distance = 0;
	int find = -1;
	for (int i = 1; i <= x; i++)
	{
		answer += 1;
		distance += i;
		if (distance == k)
		{
			find = 1;
			break;
		}
		else if (distance > k)
		{
			answer -= 1;
			distance -= i;
			find = 1;
			answer += 1;
			break;
		}
	}
	if (answer != 0 && find != -1)
	{
		return answer;
	}
	answer = 0;
	distance = 0;
	int m = int(sqrt(k));
	while (true)
	{
		distance = (1 + m) * m / 2 + (m + x) * (m - x + 1) / 2 - m;
		if (distance == k)
			break;
		else if (distance > k)
		{
			m -= 1;
			distance = (1 + m) * m / 2 + (m + x) * (m - x + 1) / 2 - m;
			break;
		}
		m += 1;
	}
	answer += (m + m - x);
	if (distance == k)
	{
		return answer;
	}
	else
	{
		int remain = k - distance;
		answer += int(remain / m);
		if (remain % m == 0)
			return answer;
		return answer + 1;
	}
}

int race()
{
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);

	int k, n;
	cin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cout << min_time(k, x) << endl;
	}
	return 0;
}
