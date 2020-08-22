#include <iostream>
#include <vector>

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
	int n;
	cin >> n;

	int m;
	cin >> m;

	Tree* computer = new Tree[n];

	for (int i = 0; i < n; i++)
	{
		computer[i].setValue(i);
	}

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		computer[a - 1].uni(&computer[b - 1]);
	}

	cout << computer[0].find()->getCount() - 1 << endl;
}