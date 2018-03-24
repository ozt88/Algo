
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

int list1[101];
int list2[101];
int cache[101][101];
int N, M;

// n부터 시작하는 부분 배열과 m부터 시작하는 부분 배열에서 
// 얻을 수 있는 최대 연결된 부분 증가 수열의 길이
// n과 m은 반드시 포함된다
int JLIS(int n, int m)
{
	int& ret = cache[n][m];
	if (ret != -1)
		return ret;

	ret = 2;
	int min = max(list1[n], list2[m]);
	for (int nextN = n + 1; nextN <= N; nextN++)
	{
		if (min < list1[nextN])
			ret = max(ret, JLIS(nextN, m) + 1);
	}

	for (int nextM = m + 1; nextM <= M; nextM++)
	{
		if (min < list2[nextM])
			ret = max(ret, JLIS(n, nextM) + 1);
	}
	return ret;
}

int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		memset(list1, 0, sizeof(list1));
		memset(list2, 0, sizeof(list2));
		memset(cache, -1, sizeof(cache));

		cin >> N >> M;

		list1[0] = numeric_limits<int>::min();
		list2[0] = numeric_limits<int>::min();

		for (int n = 1; n <= N; ++n)
			cin >> list1[n];

		for (int m = 1; m <= M; ++m)
			cin >> list2[m];

		cout << JLIS(0, 0) - 2 << endl;
	}
	return 0;
}
