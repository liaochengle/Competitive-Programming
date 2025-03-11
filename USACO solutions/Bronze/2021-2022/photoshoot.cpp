#include<iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>
using namespace std;

int photoshoot(){
	int n;
	cin >> n;
	vector<char> cows(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> cows[i];

	int times = 0;
	n -= n % 2;
	for (int i = n; i >= 2; i -= 2)
	{
		if (cows[i] == cows[i - 1])
			continue;
		//i - > ¶Î
		//ÏÂÒ»¸öÒ»¶¨ºÍÕâ¸ö²»Í¬£¡
		//iÒ»¶¨ÊÇÅ¼ÊýÎ»ÖÃµÄ
		if (cows[i] == 'G' && times % 2 == 1) //GÔÚÆæÊýÎ»
			times += 1;
		if (cows[i] == 'H' && times % 2 == 0) //HÔÚÅ¼Êý£¬ÏÂÒ»¸öÒ»¶¨²»µÈÓÚH -> GÔÚÆæÊýÎ»
			times += 1;
	}
	cout << times << endl;
	return 0;
}
