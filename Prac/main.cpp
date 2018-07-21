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
#include <math.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

i64 search(i64 min, i64 max, function<bool(i64)> check)
{
	i64 low = min;
	i64 high = max;
	i64 ret = 0;
	while (low <= high)
	{
		i64 mid = (low + high) / 2;
		if (check(mid))
		{
			low = mid + 1;
			ret = mid;
		}
		else
		{
			high = mid - 1;
		}
	}
	return ret;
}

int main()
{
	i64 N, M;
	cin >> N >> M;
	vector<i64> heights(N);
	for (auto& height : heights)
	{
		cin >> height;
	}
	const i64 MAX = 1000000000;
	
	cout << search(0, MAX, [&heights, &M](i64 cut)
	{
		i64 sum = 0;
		for (auto& h : heights)
		{
			i64 sub = h - cut;
			if (sub > 0)
			{
				sum += sub;
			}
		}
		return sum >= M;
	});
	return 0;
}
