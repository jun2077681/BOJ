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

	vector<int> v(n + 1, 0);

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		int case1 = v[i - 1] + 1;
		int case2 = i % 2 == 0 ? v[i / 2] + 1 : n + 1;
		int case3 = i % 3 == 0 ? v[i / 3] + 1 : n + 1;

		v[i] = min(min(case1, case2), case3);
	}

	cout << v[n];
}