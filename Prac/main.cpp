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

i64 table[50][50] = { 0, };

i64 solve(int n, int m)
{
	if (n == m)
		return 1;

	if (n == 1)
		return m;

	auto& ret = table[n][m];
	if (ret == -1)
	{
		ret = 0;
		// 왼쪽 맨위에 있는 점이 연결되는 경우를 먼저 따져서 나누면
		// n - 1의 더 작은 문제로 만들 수 있습니다.
		for (int i = 1; i <= m - n + 1; ++i)
		{
			ret += solve(n - 1, m - i);
		}
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	int N, M;
	for (int t = 0; t < T; ++t)
	{
		cin >> N >> M;
		memset(table, -1, sizeof(table));
		cout << solve(N, M) << '\n';
	}

	return 0;
}
