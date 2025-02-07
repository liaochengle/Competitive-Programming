#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int social_distancing_1()
{
	freopen("socdist1.in", "r", stdin);
	freopen("socdist1.out", "w", stdout);

	int n;
	cin >> n;
	string arr;
	cin >> arr;
	vector<int> distance;

	int dis = 0;	
	int first = arr.find('1');
	int endin = arr.rfind('1');
	int end = n - 1 - endin;

	//Ã»ÓÐ1 Ö»ÓÐÒ»¸ö1
	int times = count(arr.begin(), arr.end(), '1');
	if (times == 0)
	{
		cout << n - 1;
		return 0;
	}
	else if (times == 1)
	{
		if (first > end)
		{
			vector<int> temp;
			temp.push_back(first - 1);
			first = 0;
			if (end > temp[0])
				temp.push_back(end - 1);
			else
			{
				temp.push_back(int(temp[0] / 2));
				temp.push_back(temp[0]- 1 - int(temp[0] / 2));
			}
			cout << *min_element(temp.begin(), temp.end()) + 1;
			return 0;
		}
		else
		{
			vector<int> temp;
			temp.push_back(end - 1);
			end = 0;
			if (first > temp[0])
				temp.push_back(first - 1);
			else
			{
				temp.push_back(temp[0] - 1 - int(temp[0] / 2));
			}
			cout << *min_element(temp.begin(), temp.end()) + 1;
			return 0;
		}
	}
	for (int i = first+1; i <= endin; i++)
	{
		char c = arr[i];
		if (c == '0')
			dis += 1;
		else if (c == '1')
		{
			distance.push_back(dis);
			dis = 0;
		}
	}
	//cout << first << endl;
	//for (int i = 0; i < distance.size(); i++)
		//cout << distance[i] << endl;
	//cout << end << endl;
	for (int i = 0; i < 2; i++)
	{
		int max_index1 = int(max_element(distance.begin(), distance.end()) - distance.begin());
		int max_num1 = distance[max_index1];
		if (first >= max_num1 && first > end)
		{
			distance.push_back(first - 1);
			first = 0;
		}
		else if (end >= max_num1 && end > first)
		{
			distance.push_back(end - 1);
			end = 0;
		}
		else
		{
			distance.push_back(int(max_num1 / 2));
			distance.push_back(max_num1 - 1 - int(max_num1 / 2));
		}
	}
	int ans = *min_element(distance.begin(), distance.end());
	cout << ans + 1;
	return 0;
}
