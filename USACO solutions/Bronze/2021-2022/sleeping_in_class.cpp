#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int min_modify(vector<int>& numbers, int n, int sum)
{
	int answer = 0;
	int num = 0;
	int first = 0;
	int last = -1;
	for (int i = 0; i < n; i++)
	{
		num += numbers[i];
		last += 1;
		if (num == sum)
		{
			//cout << "--" << first << " " << last << endl;
			num = 0;
			answer += last - first;
			first = last + 1;
		}
	}
	//cout << sum <<  " " << answer << " " << num << endl;
	if (num != 0)
		return -1;
	else
		return answer;
}

int sleeping_in_class()
{
	int T;
	cin >> T;
	vector<int> arr(T);
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		vector<int> numbers(n);
		for (int i = 0; i < n; i++)
			cin >> numbers[i];
		int least = *max_element(numbers.begin(), numbers.end());
		int largest = 0;
		for (int i = 0; i < n; i++)
			largest += numbers[i];

		int final = n;
		for (int i = least; i <= largest; i++)
		{
			int answer = min_modify(numbers, n, i);
			//cout << answer << endl;
			if (answer == -1)
				continue;
			else
			{
				final = answer;
				break;
			}
		}
		arr[t] = final;
	}
	for (int t = 0; t < T; t++)
		cout << arr[t] << endl;
	return 0;
}

