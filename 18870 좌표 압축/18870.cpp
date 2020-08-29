#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	map<int, int> m;
	vector<int> v;

	cin >> n;

	int tmp;

	while (n--)
	{
		cin >> tmp;
		v.push_back(tmp);
		m.insert(make_pair(tmp, 1));
	}

	int num = 0;
	for (auto iter = m.begin();iter!=m.end();iter++)
	{
		iter->second = num;
		num++;
	}

	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		cout << m.find(*iter)->second << ' ';
	}
}