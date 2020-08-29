#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<bool> v(20, false);

	string c;
	int e;

	while (n--)
	{
		cin >> c;
		if (c == "add")
		{
			cin >> e;
			v[e - 1] = true;
		}
		else if (c == "remove")
		{
			cin >> e;
			v[e - 1] = false;
		}
		else if (c == "check")
		{
			cin >> e;
			if (v[e - 1])
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (c == "toggle")
		{
			cin >> e;
			
			v[e - 1] = !v[e - 1];
		}
		else if (c == "all")
		{
			v = vector<bool>(20, true);
		}
		else if (c == "empty")
		{
			v = vector<bool>(20, false);
		}
	}
}