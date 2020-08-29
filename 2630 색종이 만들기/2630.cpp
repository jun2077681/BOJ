#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

pair<int, int> divide(int n, vector<vector<int>> v);

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> v;

	for (int i = 0; i < n; i++)
	{
		vector<int> v2;
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			v2.push_back(tmp);
		}
		v.push_back(v2);
	}

	pair<int, int> result = divide(n, v);
	cout << result.first << '\n' << result.second << '\n';
}

pair<int, int> divide(int n, vector<vector<int>> v)
{
	vector<vector<int>> divide_vector[4];
	bool is_same[4] = { true, true, true, true };
	pair<int, int> p = make_pair(0, 0);

	int color[4];

	color[0] = v[0][0];
	for (int i = 0; i < n / 2; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n / 2; j++)
		{
			tmp.push_back(v[i][j]);
			is_same[0] &= (color[0] == v[i][j]);
		}
		divide_vector[0].push_back(tmp);
	}

	color[1] = v[n / 2][0];
	for (int i = n / 2; i < n; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n / 2; j++)
		{
			tmp.push_back(v[i][j]);
			is_same[1] &= (color[1] == v[i][j]);
		}
		divide_vector[1].push_back(tmp);
	}

	color[2] = v[0][n / 2];
	for (int i = 0; i < n / 2; i++)
	{
		vector<int> tmp;
		for (int j = n / 2; j < n; j++)
		{
			tmp.push_back(v[i][j]);
			is_same[2] &= (color[2] == v[i][j]);
		}
		divide_vector[2].push_back(tmp);
	}

	color[3] = v[n / 2][n / 2];
	for (int i = n / 2; i < n; i++)
	{
		vector<int> tmp;
		for (int j = n / 2; j < n; j++)
		{
			tmp.push_back(v[i][j]);
			is_same[3] &= (color[3] == v[i][j]);
		}
		divide_vector[3].push_back(tmp);
	}

	for (int i = 0; i < 4; i++)
	{
		if (is_same[i])
		{
			if (color[i] == 0) p.first++;
			else p.second++;
		}
		else
		{
			pair<int, int> tmp = divide(n / 2, divide_vector[i]);
			p.first += tmp.first;
			p.second += tmp.second;
		}
	}
	return p;
}