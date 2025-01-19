#include <stdio.h>
#include <iostream>
using namespace std;


int promotion_counting()
{
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	int before[4] = { 0 };
	int after[4] = { 0 };
	int sum_before = 0;
	int sum_after = 0;
	for (int i = 0; i < 4; i++)
		scanf("%d %d", &before[i], &after[i]);

	int new_platinum = after[3] - before[3];
	before[2] -= new_platinum;
	int new_gold = after[2] - before[2];
	before[1] -= new_gold;
	int new_silver = after[1] - before[1];

	cout << new_silver << endl
		<< new_gold << endl
		<< new_platinum << endl;
	return 0;
}
