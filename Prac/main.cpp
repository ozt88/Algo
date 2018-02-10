#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;


struct QuadNode
{
	char content;
	vector<QuadNode*> children;

	void Reverse()
	{
		if (children.empty())
			return;

		iter_swap(children.begin(), children.begin() + 2);
		iter_swap(children.begin() + 1, children.begin() + 3);

		for (auto child : children)
		{
			child->Reverse();
		}
	}
	
	string ToString()
	{
		string ret;
		ret.push_back(content);
		for (auto q : children)
		{
			ret += q->ToString();
		}
		return ret;
	}
};

QuadNode* MakeQuad(string& input)
{
	if (input.empty())
		return nullptr;

	auto q = new QuadNode();
	q->content = input[0];
	input = input.substr(1, input.length());

	if (q->content == 'x')
	{
		for (int i = 0; i < 4; ++i)
		{
			auto child = MakeQuad(input);
			if (child == nullptr)
				break;

			q->children.push_back(child);
		}
	}
	return q;
}

string Solve(string input)
{
	auto q = MakeQuad(input);
	q->Reverse();
	return q->ToString();
}

int main()
{
	int C;
	cin >> C;
	string input;
	for (int c = 0; c < C; ++c)
	{
		cin >> input;
		cout << Solve(input) << endl;
	}

	return 0;
}
