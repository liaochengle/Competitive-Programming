#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct board
{
	int x1, y1, x2, y2;
	int area()
	{
		return (x2 - x1) * (y2 - y1);
	}
};

int covered_area(board mower, board feed)
{
	int x = max(0, min(mower.x2, feed.x2) - max(mower.x1, feed.x1));
	int y = max(0, min(mower.y2, feed.y2) - max(mower.y1, feed.y1));
	return x * y;
}

int bloacked_billboard2()
{
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	board mower, feed;
	cin >> mower.x1 >> mower.y1 >> mower.x2 >> mower.y2;
	cin >> feed.x1 >> feed.y1 >> feed.x2 >> feed.y2;
	int covered = covered_area(mower, feed);
	if (covered == 0)
		printf("%d", mower.area());
	else if (covered == mower.area())
		printf("%d", 0);
	else 
	{
		//Ê®×ÖÐÎµÄ²»¿ÉÒÔ£¡»¹ÊÇ¹¹ÔìµÄÌØÊâÇé¿ö²»¹»
		if (feed.y1 <= mower.y1 && mower.y2 <= feed.y2)
		{
			if (mower.x1 < feed.x1 && feed.x2 < mower.x2)
			{
				cout << mower.area();
				return 0;
			}
			printf("%d", mower.area() - covered);
			return 0;
		}
		else if (feed.x1 <= mower.x1 && mower.x2 <= feed.x2)
		{
			if (mower.y1 < feed.y1 && feed.y2 < mower.y2)
			{
				cout << mower.area();
				return 0;
			}
			cout << mower.area() - covered;
			return 0;
		}
		else
			printf("%d", mower.area());
	}
	return 0;
}
