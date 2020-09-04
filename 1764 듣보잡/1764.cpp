#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<string> s1;
	vector<string> s2;

	string s;

	while (n--)
	{
		cin >> s;
		s1.push_back(s);
	}
	while (m--)
	{
		cin >> s;
		s2.push_back(s);
	}

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	vector<string> result;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(result));
	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (auto i : result)
	{
		cout << i << '\n';
	}
}