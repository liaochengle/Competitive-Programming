#include <stdio.h>
#include <algorithm>
using namespace std;

int speeding_ticket()
{
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	int limit[101] = { 0 };
	int speed[101] = { 0 };
	int n, m;
	scanf("%d %d", &n, &m);
	int last_limit = 1;
	int last_speed = 1;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		for (int j = last_limit; j < last_limit + a; j++)
			limit[j] = b;
		last_limit += a;
	}
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		for (int j = last_speed; j < last_speed + a; j++)
			speed[j] = b;
		last_speed += a;
	}
	//for (int i = 0; i < 101; i++)
		//cout << limit[i] << endl;
	int ans = 0;
	for (int i = 1; i < 101; i++)
	{
		ans = max(ans, speed[i] - limit[i]);
	}
	printf("%d", ans);
	return 0;
}
