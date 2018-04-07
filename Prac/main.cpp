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

void TripleSort(vector<int>& _list)
{
	bool done = false;
	while (!done)
	{
		done = true;
		for (int i = 0; i < _list.size() - 2; ++i)
		{
			if (_list[i] > _list[i + 2])
			{
				done = false;
				iter_swap(_list.begin() + i, _list.begin() + i + 2);
			}
		}
	}
}

int Solve(vector<int>& _list)
{
	TripleSort(_list);
	for (int i = 0; i < _list.size() - 1; ++i)
	{
		if (_list[i] > _list[i + 1])
			return i;
	}
	return -1;
}

int FasterSolve(const vector<int>& _list)
{
	vector<int> evenList,oddList;
	for (int i = 0; i < _list.size(); ++i)
	{
		if (i % 2)
			oddList.push_back(_list[i]);
		else
			evenList.push_back(_list[i]);
	}

	sort(evenList.begin(), evenList.end());
	sort(oddList.begin(), oddList.end());

	for (int i = 0; i < _list.size() / 2; ++i)
	{
		if (evenList[i] > oddList[i])
			return i * 2;
		else if (i + 1 < evenList.size() && oddList[i] > evenList[i + 1])
			return i * 2 + 1;

	}

	return -1;
}

int main()
{	
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		vector<int> list(N);
		for (auto& num : list)
			cin >> num;

		int errorIndex = FasterSolve(list);
		string ret;
		if (errorIndex == -1)
			ret = "OK";
		else
			ret = to_string(errorIndex);

		cout << "Case #" << i + 1 << ": " << ret << endl;
	}
	return 0;
}
