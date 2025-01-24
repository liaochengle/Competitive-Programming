#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int the_cow_signal()
{
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	vector<string> signal(M);
	for (int i = 0; i < M; i++)
		cin >> signal[i];
	vector<string>new_signal(K * M);

	for (int i = 0; i < M; i++)
	{
		string new_string;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < K; k++)
				new_string.push_back(signal[i][j]);
		}
		for (int k = i * K; k < (i + 1) * K; k++)
		{
			new_signal[k] = new_string;
		}
	}
	for (int i = 0; i < K * M; i++)
		cout << new_signal[i] << endl;
	return 0;
}
