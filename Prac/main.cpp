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

int GetLongestSequence(int index)
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
			ret = max(ret, GetLongestSequence(i));
		}
		cout << ret << endl;
	}

	return 0;
}
