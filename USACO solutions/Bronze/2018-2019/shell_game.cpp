#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int* arr, int a, int b)
{
	int temp = arr[a - 1];
	arr[a - 1] = arr[b - 1];
	arr[b - 1] = temp;
}

int shell_game()
{
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

	int n;
	scanf("%d", &n);
	int arr[3] = { 1, 2, 3 };
	vector<int> guess(n, 0);
	for (int i = 0; i < n; i++)
	{
		int a, b, g;
		cin >> a >> b >> g;
		swap(arr, a, b);
		guess[i] = arr[g - 1];
	}
	int ans = 0;
	for (int i = 0; i < 3; i++)
	{
		int num = count(guess.begin(), guess.end(), i + 1);
		ans = max(num, ans);
	}
	printf("%d", ans);
	return 0;
}
