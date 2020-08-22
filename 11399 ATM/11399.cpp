#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer = answer + (i + 1) * v[n - i - 1];
	}
	cout << answer << endl;	
}