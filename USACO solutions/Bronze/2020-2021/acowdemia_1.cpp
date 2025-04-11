#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#in
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int new_min(vector<int>& citations, int h, int l)
{
	int num = citations[h - 1];
	if (l == 0)
		return num;

	vector<int> temp(citations.begin(), citations.begin() + h);
	int times = count(temp.begin(), temp.end(), num);
	if (times <= l)
		return num + 1;
	else
		return num ;
}

int acowdemia_1()
{
	int n, l;
	cin >> n >> l;
	vector<int> citations(n);
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		citations[i] = num;
	}
	sort(citations.begin(), citations.end(), cmp);

	int h = 1; 
	for (h; h <= n; h++)
	{
		//cout << h << " " << new_min(citations, h, l) << endl;
		if (h > citations[h - 1])
		{
			if (h > new_min(citations, h, l))
				break;
		}
	}
	cout << h - 1 << endl;
	return 0;
}
