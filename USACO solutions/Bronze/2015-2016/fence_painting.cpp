#include <stdio.h>
#include <algorithm>
#inclu
using namespace std;
int fence_painting()
{
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	int a, b, c, d;
	scanf("%d %d", &a,&b);
	scanf("%d %d", &c, &d);

	int small = min(a, c);
	int big = max(b, d);
	int arr[105] = { 0 };
	for (int i = a; i < b; i++)
		arr[i] = 1;
	for (int i = c; i < d; i++)
		arr[i] = 1;
	int ans = 0;
	for (int i = small; i < big; i++)
		if (arr[i] == 1)
			ans += 1;
	printf("%d", ans);
	return 0;
}
