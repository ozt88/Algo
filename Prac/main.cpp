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

int N = 0;
int triangle[100][100] = { 0, };
int cache[100][100] = { 0, };


int GetBiggestPath(int x, int y)
{
	if (y == N - 1)
		return triangle[x][y];
	
	if (cache[x][y] != 0)
		return cache[x][y];
	
	cache[x][y] = max(GetBiggestPath(x, y + 1), GetBiggestPath(x + 1, y + 1)) + triangle[x][y];	
	return cache[x][y];
}


int main()
{
	int C;
	cin >> C;
	for (int c = 0; c < C; ++c)
	{
		memset(triangle, 0, sizeof(triangle));
		memset(cache, 0, sizeof(triangle));

		cin >> N;
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x <= y; ++x)
			{
				cin >> triangle[x][y];
			}
		}
		cout << GetBiggestPath(0, 0) << endl;
	}

	return 0;
}
