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

const int MAX_NUM = 10000001;
int cache[MAX_NUM] = { 0, };

int GetMinCalcCount(int num)
{
	if (num == 1)
		return 0;

	int ret = cache[num];
	if (ret == 0)
	{
		int minValue = GetMinCalcCount(num - 1);

		if (num % 3 == 0)
			minValue = min(minValue, GetMinCalcCount(num / 3));

		if (num % 2 == 0)
			minValue = min(minValue, GetMinCalcCount(num / 2));

		ret = minValue + 1;
		cache[num] = ret;
	}
	return ret;
}

int main()
{
	int X;
	cin >> X;
	cout << GetMinCalcCount(X);
	return 0;
}
