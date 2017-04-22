#pragma once
#include <vector>

class FenwickTree
{
public:
	FenwickTree();
	~FenwickTree();
	
	void Init(std::vector<long long> input);
	long long Sum(int index);
	void Update(int index, long long diff);

	std::vector<long long> m_tree;
};

