#include <stdio.h>
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int do_you_know_your_abcs()
{
	vector<int> nums(7);
	for (int i = 0; i < 7; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	int a, b, c;
	int ab, bc, ac, abc;

	a = nums[0];
	nums[0] = 0;
	abc = nums[6];
	nums[6] = 0;
	bc = abc - a;
	int bc_ind = find(nums.begin(), nums.end(), bc) - nums.begin();
	nums[bc_ind] = 0;

	bool flag = false;
	for (int i = 0; i < 7; i++)
	{
		if (flag)
			break;
		int b_temp, c_temp;
		if (nums[i] == 0)
			continue;
		if (nums[i] <= int(bc / 2))
		{
			b_temp = nums[i];
			nums[i] = 0;
			if (find(nums.begin() + i, nums.end(), bc - b_temp) != nums.end())
			{
				b = b_temp;
				c = bc - b;
				flag = true;
			}
		}
	}
	cout << a << " " << b << " " << c;
	return 0;
}


