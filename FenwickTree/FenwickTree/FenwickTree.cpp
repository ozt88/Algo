#include "FenwickTree.h"

FenwickTree::FenwickTree()
{
}

FenwickTree::~FenwickTree()
{
}

void FenwickTree::Init(std::vector<long long> input)
{
	for (int i = 0 ;i < input.size(); ++i)
	{
		Update(i, input[i]);
	}
}

long long FenwickTree::Sum(int index)
{
	long long ret = 0;
	while (index > 0)
	{
		ret += m_tree[index];
		index -= (index & -index);
	}
	return ret;
}

void FenwickTree::Update(int index, long long diff)
{
	while (index < m_tree.size())
	{
		m_tree[index] += diff;
		index += (index & -index);
	}
}
