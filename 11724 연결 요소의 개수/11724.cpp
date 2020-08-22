#include <iostream>
#include <set>

using namespace std;

class Tree 
{
private:
	int element;
	int rank;
	int count;
	Tree* parent;
public:
	void setValue(int _element) { element = _element; }
	void setCount(int _count) { count = _count; }
	int getCount() { return count; }
	int getValue() { return element; }
	void uni(Tree* y)
	{
		Tree* xroot = this->find();
		Tree* yroot = y->find();

		if (xroot == yroot) return;

		if (xroot->rank < yroot->rank)
		{
			int xroot_count = xroot->find()->count;
			xroot->parent = yroot;
			yroot->find()->setCount(yroot->count + xroot_count);
		}
		else if (xroot->rank > yroot->rank)
		{
			int yroot_count = yroot->find()->count;
			yroot->parent = xroot;
			xroot->find()->setCount(xroot->count + yroot_count);
		}
		else
		{
			int yroot_count = yroot->find()->count;
			yroot->parent = xroot;
			xroot->find()->setCount(xroot->find()->count + yroot_count);
			xroot->rank += 1;
		}
	}
	Tree* find()
	{
		if (this->parent != this)
		{
			this->parent = this->parent->find();
		}
		return this->parent;
	}

	bool operator==(const Tree& other) const
	{
		return element == other.element;
	}

	bool operator!=(const Tree& other) const
	{
		return element != other.element;
	}

	Tree()
	{
		element = 0;
		parent = this;
		rank = 0;
		count = 1;
	}
};

int main(void)
{
	int n, m;
	cin >> n >> m;

	Tree* point = new Tree[n];

	for (int i = 0; i < n; i++)
	{
		point[i].setValue(i);
	}

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		point[a - 1].uni(&point[b - 1]);
	}

	set<int> s;
	for (int i = 0; i < n; i++)
	{
		s.insert(point[i].find()->getValue());
	}
	cout << s.size() << endl;
}