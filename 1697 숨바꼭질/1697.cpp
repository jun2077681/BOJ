#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> v(100001, 999999);
	v[n] = 0;

	queue<int> current;
	queue<int> next;

	next.push(n);

	int time = 0;
	while (++time)
	{
		if (v[k] != 999999) break;

		queue<int> emt;
		swap(current, next);
		swap(next, emt);

		while (current.size())
		{
			int p = current.front();
			current.pop();

			if (p + 1 < 100001 && v[p + 1] == 999999)
			{
				v[p + 1] = time;
				next.push(p + 1);
			}
			if (p - 1 >= 0 && v[p - 1] == 999999) 
			{
				v[p - 1] = time;
				next.push(p - 1);
			}
			if (p * 2 < 100001 && v[p * 2] == 999999)
			{
				v[p * 2] = time;
				next.push(p * 2);
			}
		}
	}

	cout << v[k] << endl;
}