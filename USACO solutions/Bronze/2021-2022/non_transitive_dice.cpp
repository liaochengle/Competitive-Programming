#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

bool win(vector<int>& A, vector<int>& B)
{
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (A[i] > B[j])
				ans1 += 1;
			else if (B[j] > A[i])
				ans2 += 1;
		}
	}

	if (ans1 > ans2)
		return true;
	else
		return false;
}

void printVector(vector<int>& A)
{
	for (int i = 0; i < 4; i++)
		cout << A[i] << " ";
	cout << endl;
}

bool valid_solution(vector<int>& A, vector<int>& B)
{
	for (int i = 1; i < 11; i++)
		for (int j = 1;j < 11; j++)
			for (int k = 1; k < 11; k++)
				for (int l = 1; l < 11; l++)
				{
					vector<int> C = { i, j, k, l };
					if (win(A, B) && win(B, C) && win(C, A))
						return true;
					if (win(B, A) && win(A, C) && win(C, B))
						return true;
				}
	return false;
}

int non_transitive_dice()
{
	int N;
	cin >> N;
	vector<string>answers(N);
	vector<int> nums(10);
	for (int i = 0; i < 10; i++)
		nums[i] = i + 1;
	for (int n = 0; n < N; n++)
	{
		vector<int> A(4);
		vector<int> B(4);
		for (int i = 0; i < 4; i++)
			cin >> A[i];
		for (int i = 0; i < 4; i++)
			cin >> B[i];
		if (valid_solution(A, B))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}

