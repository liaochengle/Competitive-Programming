#include <iostream>
#include <stdio.h>
#include <vector>
#inclu
using namespace std;
//yay

void new_swap(vector<int>& arr, int a1, int a2, int n)
{
	int range = (a1 + a2) / 2;
	for (int i = a1; i <= range; i++)
	{
		int temp = arr[i];
		arr[i] = arr[a1 + a2 - i];
		arr[a1 + a2 - i] = temp;
	}
	//for (int i = 1; i <= n; i++)
		//cout << arr[i] << " ";
	//cout << endl;
}

int swapity_swap()
{
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int n;
	long long k;
	int a1, a2;
	int b1, b2;
	cin >> n >> k;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	vector<int> ori(n + 1, 0);
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
		ori[i] = i;
	}

	int loop = 0;
	vector<vector<int>> results;
	results.push_back(ori);
	do
	{
		new_swap(arr, a1, a2, n);
		new_swap(arr, b1, b2, n);
		loop += 1;
		results.push_back(arr);
		if (loop == k)
		{
			for (int i = 1; i <= n; i++)
				cout << arr[i] << endl;
			return 0;
		}
	} while (arr != ori);

	long long times = k % loop;
	vector<int> finalans = results[times];
	for (int i = 1; i <= n; i++)
		cout << finalans[i] << endl;
	return 0;
}

