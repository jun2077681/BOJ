#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	vector<vector<int>> table;
	int row, col;
	cin >> row >> col;
	table.assign(col, vector<int>(row, 0));

	queue<pair<int, int>> current;
	queue<pair<int, int>> next;
	int count = 0;
	int day = 0;

	for (int i = 0; i < table.size(); i++) 
	{
		for (int j = 0; j < table[i].size(); j++) 
		{
			cin >> table[i][j];
			if (table[i][j] == 1)
			{
				next.push(pair<int, int>(i, j));
			}
			else if (table[i][j] == 0)
			{
				count += 1;
			}
		}
	}

	while (++day)
	{
		queue<pair<int, int>> emt;
		swap(current, next);
		swap(next, emt);

		while (current.size())
		{
			pair<int, int> tomato = current.front();
			current.pop();
			int x = tomato.first;
			int y = tomato.second;

			if (x - 1 >= 0 && table[x - 1][y] == 0) //left
			{
				table[x - 1][y] = 1;
				count -= 1;
				next.push(pair<int, int>(x - 1, y));
			}
			if (x + 1 < table.size() && table[x + 1][y] == 0) //right
			{
				table[x + 1][y] = 1;
				count -= 1;
				next.push(pair<int, int>(x + 1, y));
			}
			if (y - 1 >= 0 && table[x][y - 1] == 0) //down
			{
				table[x][y - 1] = 1;
				count -= 1;
				next.push(pair<int, int>(x, y - 1));
			}
			if (y + 1 < table[0].size() && table[x][y + 1] == 0) //up
			{
				table[x][y + 1] = 1;
				count -= 1;
				next.push(pair<int, int>(x, y + 1));
			}
		}
		
		if (!next.size()) break;
	}

	if (!count) cout << day - 1 << endl;
	else cout << -1 << endl;
}