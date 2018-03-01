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

int main()
{
	int N, r, c;
	cin >> N >> r >> c;

	r++, c++;
	int count = 0;
	int size = pow(2, N);
	while (size > 1)
	{
		size = size / 2;
		bool isXBigger = size < c;
		bool isYBigger = size < r;
		if (isXBigger)
			c -= size;
		if (isYBigger)
			r -= size;

		int index = 2 * (isYBigger) + isXBigger;
		count += size * size * index;
	}
	cout << count << endl;

	return 0;
}
