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

int N;
int list[500];
int cache[500];

// n^2 using DP
int Lis(int index)
{
	if (index == N)
		return 0;

	if (cache[index] != -1)
		return cache[index];

	int& ret = cache[index];
	ret = 1;
	for (int i = index + 1; i < N; ++i)
	{
		if(list[index] < list[i])
			ret = max(ret, GetLongestSequence(i) + 1);
	}
	return ret;
}

// n log n using lower_bound(binary search)
int LisLowerBound(const vector<int> list)
{
	if (list.empty())
		return 0;

	vector<int> minValuePerLength;
	for (int num : list)
	{
		if (minValuePerLength.empty() || minValuePerLength.back() < num)
			minValuePerLength.push_back(num);
		else
			*lower_bound(minValuePerLength.begin(), minValuePerLength.end(), num) = num;
	}
	return minValuePerLength.size();
}

int main()
{
	int C;
	cin >> C;
	for (int c = 0; c < C; ++c)
	{
		memset(list, 0, sizeof(list));
		memset(cache, -1, sizeof(cache));

		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> list[i];
		}

		int ret = 0;
		for (int i = 0; i < N; ++i)
		{
			ret = max(ret, Lis(i));
		}
		cout << ret << endl;
	}

	return 0;
}
