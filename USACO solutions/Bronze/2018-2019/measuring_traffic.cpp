#include <bits/stdc++.h>
using namespace std;

struct mile
{
	string status;
	int min, max;
};

int measuring_traffic()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	int n;
	cin >> n;
	vector<mile> traffic(n);
	for (int i = 0; i < n; i++)
	{
		cin >> traffic[i].status;
		cin >> traffic[i].min >> traffic[i].max;
	}

	int finalmin = 0, finalmax = 1000;
	int start = 0;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (!flag)
			break;
		while (traffic[i].status == "none" && i < n)
		{
			finalmin = max(traffic[i].min, finalmin);
			finalmax = min(traffic[i].max, finalmax);
			start = i;
			i += 1;
			flag = false;
		}
	}

	for (int i = start; i < n; i++)
	{
		if (traffic[i].status == "on")
		{
			finalmin += traffic[i].min;
			finalmax += traffic[i].max;
		}
		else if (traffic[i].status == "none")
		{
			finalmin = max(finalmin, traffic[i].min);
			finalmax = min(finalmax, traffic[i].max);
		}
		else if (traffic[i].status == "off")
		{
			finalmin -= traffic[i].max;
			//aaaaaaaaaaaËÙ¶È²»¿ÉÒÔÎª¸ºÊýÑ½£¡£¡£¡
			finalmin = max(0, finalmin);
			finalmax -= traffic[i].min;
			finalmax = max(0, finalmax);
		}
	}

	int startmin = finalmin;
	int startmax = finalmax;
	for (int i = n - 1; i >= 0; i--)
	{
		if (traffic[i].status == "on")
		{
			startmin -= traffic[i].max;
			startmin = max(0, startmin);
			startmax -= traffic[i].min;
			startmax = max(0, startmax);
		}
		else if (traffic[i].status == "none")
		{
			startmin = max(startmin, traffic[i].min);
			startmax = min(startmax, traffic[i].max);
		}
		else if (traffic[i].status == "off")
		{
			startmin += traffic[i].min;
			startmax += traffic[i].max;
		}
	}
	cout << startmin << " " << startmax << endl;

	cout << finalmin << " " << finalmax << endl;
	return 0;
}

