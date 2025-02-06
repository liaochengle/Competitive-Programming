#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct point
{
	int x, y;
};

int maxarea(int index, vector<point>& points, int n)
{
	int maxy = 0, maxx = 0;
	point temp = points[index];
	for (int i = 0; i < n; i++)
	{
		if (i == index)
			continue;
		if (temp.x == points[i].x)
			maxy = max(maxy, abs(temp.y - points[i].y));
		else if (temp.y == points[i].y)
			maxx = max(maxx, abs(temp.x - points[i].x));
	}
	return maxy * maxx;
}

int triangles()
{
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	int n;
	cin >> n;
	vector<point> points;
	for (int i = 0; i < n; i++)
	{
		point temp;
		cin >> temp.x >> temp.y;
		points.push_back(temp);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(maxarea(i, points, n), ans);
	}
	cout << ans;
	return 0;
}
