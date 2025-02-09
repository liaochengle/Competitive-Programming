#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int even_more_odd_photos()
{
	int n;
	cin >> n;
	int even = 0;
	int odd = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num % 2 == 0)
			even += 1;
		else
			odd += 1;
	}
	if (even > odd)
	{
		cout << odd * 2 + 1;
		return 0;
	}
	else if (even == odd)
	{
		cout << odd * 2;
		return 0;
	}
	else
	{
		int answer = 0;
		answer += even * 2;
		odd -= even;
		int q = int(odd / 3);
		answer += q * 2;
		int re = odd % 3;
		if (re == 2)
			answer += 1;
		else if (re == 1)
			answer -= 1;
		cout << answer;
		return 0;
	}
	return 0;
}


