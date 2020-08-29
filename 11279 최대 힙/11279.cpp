#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> v = {};
	make_heap(v.begin(), v.end());

	while (n--)
	{
		int x;
		cin >> x;
		if (x)
		{
			v.push_back(x);
			push_heap(v.begin(), v.end());
		}
		else
		{
			if (v.size())
			{
				cout << v.front() << '\n';
				pop_heap(v.begin(), v.end());
				v.pop_back();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
	}
}