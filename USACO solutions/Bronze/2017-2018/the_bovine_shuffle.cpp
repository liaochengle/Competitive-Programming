#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int the_bovine_shuffle()
{
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		nums[i] = i+1;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	vector<int> id(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &id[i]);
	
	for (int i = 0; i < 3; i++)
	{
		vector<int> new_arr(n, 0);
		for (int j = 0; j < n; j++)
		{
			new_arr[arr[j] - 1] = nums[j];
		}
		nums = new_arr;
	}
	
	//ÕâÀïÂß¼­ºÃÂÒ
	//ÏÂ´Î£¬Ã»ÏëÇå³þ£¬ÕæµÄ±ðÏÂ±Ê£¡³¤½ÌÑµÁË°É
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		ans[nums[i] - 1] = id[i];
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}

