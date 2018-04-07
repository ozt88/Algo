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

int farm[1001][1001] = { 0, };


bool Check9Done(int _x, int _y)
{
	for (int x = _x - 1; x <= _x + 1; ++x)
	{
		for (int y = _y - 1; y <= _y + 1; ++y)
		{
			if (farm[x][y] == 0)
				return false;
		}
	}
	return true;
}

bool WorkUntil9Done(int _x, int _y)
{
	int xDone, yDone;
	int count = 0;
	while (!Check9Done(_x, _y))
	{
		cout << _x << ' ' << _y << endl << flush;
		cin >> xDone >> yDone;

		if (xDone == -1 || yDone == -1)
			return false;

		if (xDone == 0 && yDone == 0)
			return false;

		farm[xDone][yDone] = 1;
	}
	return true;
}

bool Work(int _a)
{
	memset(farm, 0, sizeof(farm));
	int sufficient = (int)(ceil(sqrt((double)_a / 9)));
	for (int x = 0; x < sufficient; ++x)
	{
		for (int y = 0; y < sufficient; ++y)
		{
			if (!WorkUntil9Done(x * 3 + 2, y * 3 + 2))
				return false;
		}
	}
	return true;
}

int main()
{	
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int a;
		cin >> a;
		Work(a);
	}
	return 0;
}
