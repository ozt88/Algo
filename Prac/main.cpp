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


int cache[101][101];
int input[101][101];

bool IsValidGame(int x, int y)
{

}

int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		memset(input, 0, 101 * 101);
		memset(cache, 0, 101 * 101);
		int n;
		cin >> n;
		for (int y = 0; y < n; ++y)
			for (int x = 0; x < n; ++x)
				cin >> input[x][y];

		cout << IsValidGame(0, 0) ? "YES" : "NO";
	}
	
	return 0;
}
