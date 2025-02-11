#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printVector(vector<string>& temp)
{
	for (int i = 0; i < temp.size(); i++)
		cout << temp[i];
	cout << endl;
}

void seniority(vector<vector<string>>& data, vector<vector<string>>&senior, vector<string> names,int i, int j, int k)
{
	string cowa = names[i];
	string cowb = names[j];
	//cout << cowa << " " << cowb << endl;
	int ax = 0, bx = 0;
	bool flag = true;
	for (int m = 0; m < k; m++)
	{
		int indexa = find(data[m].begin(), data[m].end(), cowa) - data[m].begin();
		int indexb = find(data[m].begin(), data[m].end(), cowb) - data[m].begin();
		vector<string> temp;
		//cout << indexa << " " << indexb << " " << endl;
		int start = min(indexa, indexb);
		int end = max(indexa, indexb);
		for (int n = start; n <= end; n++)
			temp.push_back(data[m][n]);
		//printVector(temp);
		vector<string> sorted = temp;
		sort(sorted.begin(), sorted.end());
		if (sorted != temp)
		{
			flag = false;
			ax = indexa;
			bx = indexb;
			//cout << i << " " << j <<" " << ax << " " << bx;
			break;
		}
	}
	if (flag)
	{
		senior[i][j] = '?';
		senior[j][i] = '?';
	}
	else
	{
		if (ax > bx)
		{
			senior[i][j] = '1';
			senior[j][i] = '0';
		}
		else
		{
			senior[j][i] = '1';
			senior[i][j] = '0';
		}
	}
	senior[i][i] = 'B';
	senior[j][j] = 'B';
}

int main()
{
	int k, n;
	cin >> k >> n;
	vector<string> names(n);
	vector<vector<string>> data(k, vector<string>(n));
	for (int i = 0; i < n; i++)
		cin >> names[i];
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> data[i][j];
	}
	vector<vector<string>> senior(n, vector<string>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			seniority(data, senior, names, i, j, k);
		}
	}
	for (int i = 0; i < n; i++)
		printVector(senior[i]);
	return 0;
}

