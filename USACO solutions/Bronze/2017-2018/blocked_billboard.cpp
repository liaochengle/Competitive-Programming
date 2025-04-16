#include <stdio.h>
#include <algorithm>
#include <iostream>
#include
using namespace std;

struct board
{
	int x1, y1, x2, y2;
	int area()
	{
		return (x2 - x1)* (y2 - y1);
	}
};

int blocked_billboard()
{
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	board b1, b2, s1;
	cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
	cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
	cin >> s1.x1 >> s1.y1 >> s1.x2 >> s1.y2;

	int x_1 = max(0, min(s1.x2, b1.x2) - max(s1.x1, b1.x1));
	int y_1 = max(0, min(s1.y2, b1.y2) - max(s1.y1, b1.y1));
	int area1 = max(0, x_1 * y_1);
	int x_2 = max(0, min(s1.x2, b2.x2) - max(s1.x1, b2.x1));
	int y_2 = max(0, min(s1.y2, b2.y2) - max(s1.y1, b2.y1));
	int area2 = max(0, x_2 * y_2);
	cout << b1.area() - area1 + b2.area() - area2;
	return 0;
}
