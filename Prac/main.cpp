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

//it's bad to use non-const reference in recursive function.
//cuz you can't find the original stack status.
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

//too much object, slow & complex
//make it simple!
string Solve(string input)
{
	auto q = MakeQuad(input);
	q->Reverse();
	return q->ToString();
}


//so simple bitch
string BookIter(string input, int offset)
{
	if (input.length() <= offset)
		return "";

	char head = input[offset++];
	if (head != 'x')
		return string(1, head);
	
	auto c0 = BookIter(input, offset);
	offset += c0.length();
	auto c1 = BookIter(input, offset);
	offset += c1.length();
	auto c2 = BookIter(input, offset);
	offset += c2.length();
	auto c3 = BookIter(input, offset);

	return head + c2 + c3 + c0 + c1;
}

string BookSolve(string input)
{
	return BookIter(input, 0);
}


int main()
{
	int C;
	cin >> C;
	string input;
	for (int c = 0; c < C; ++c)
	{
		cin >> input;
		cout << BookSolve(input) << endl;
	}

	return 0;
}
