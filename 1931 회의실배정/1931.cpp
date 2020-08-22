#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

#define INT_MAX 2147483647

int main(void)
{
	int n;

	cin >> n;

	map<int, pair<int, int>> m; //start, (end, count_equal)
	map<int, int> max_count;
	int result = 0;
	int last_count = 0;

	while (n--)
	{
		int start, end;
		cin >> start >> end;

		if (m.find(start) == m.end()) //new value
		{
			m[start] = make_pair(end, start == end ? 1 : 0);
		}
		else
		{
			if (start == end)
			{
				m[start].second += 1;
			}
			else if (end < m[start].first || m[start].first == start)
			{
				m[start].first = end;
			}
		}
		max_count[start] = 0;
		max_count[end] = 0;
	}

	for (auto iter = max_count.begin(); iter != max_count.end(); iter++)
	{
		result = max(result, iter->second);
		auto next_node = m.find(iter->first);

		if (next_node != m.end())
		{
			int same = 1;
			if (next_node->first == next_node->second.first) same = 0;
			max_count[next_node->second.first] = max(max_count[next_node->second.first], result + next_node->second.second + same);
			if (same == 0)
			{
				result = max(result, max_count[next_node->second.first]);
			}
		}
	}

	cout << max(last_count, result) << endl;
}