#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map<string, string> m1;

	string s;

	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		m1[s] = to_string(i);
		m1[to_string(i)] = s;
	}

	while (m--)
	{
		cin >> s;
		cout << m1[s] << '\n';
	}
}