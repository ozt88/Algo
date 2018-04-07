
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

int getDamage(const string& P)
{
	int damageSum = 0;
	int curDamage = 1;
	for (auto c : P)
	{
		if (c == 'C')
			curDamage *= 2;
		else if (c == 'S')
			damageSum += curDamage;
	}
	return damageSum;
}

string solve(int D, string& P)
{
	if (getDamage(P) <= D)
		return to_string(0);

	int moveCount = 0;
	size_t lastSPos, lastMovableCPos;
	while (true) 
	{
		lastSPos = P.find_last_of('S');
		lastMovableCPos = P.find_last_of('C', lastSPos);
		if (lastMovableCPos == string::npos)
			return "IMPOSSIBLE";

		for (;lastMovableCPos < lastSPos; ++lastMovableCPos)
		{
			moveCount++;
			iter_swap(P.begin() + lastMovableCPos, P.begin() + lastMovableCPos + 1 );

			if (getDamage(P) <= D)
				return to_string(moveCount);
		}
	}
}

int main()
{	
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int D;
		string P;
		cin >> D >> P;
		cout << "Case #" << i + 1 << ": " << solve(D, P) << endl;
	}
	return 0;
}
