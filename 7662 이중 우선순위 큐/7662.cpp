#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--)
	{
		int k;
		cin >> k;

		multiset<int> queue;
		
		string s;
		int n;
		int index = 0;
		while (k--)
		{
			cin >> s >> n;
			if (s == "I")
			{
				queue.insert(n);
			}
			else if (s == "D")
			{
				if (queue.size())
				{
					if (n == 1)
					{
						queue.erase(queue.find(*queue.rbegin()));
					}
					else if (n == -1)
					{
						queue.erase(queue.find(*queue.begin()));
					}
				}
			}
		}
		if (queue.size())
		{
			cout << *queue.rbegin() << ' ' << *queue.begin() << '\n';
		}
		else
		{
			cout << "EMPTY\n";
		}
	}
}