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

vector<string> waffle;
int R, C, H, V;
int share;

bool Check(vector<int>& hCut, vector<int>& vCut, int newH, int newV, int newCount)
{
	int lastH = 0;
	int lastV = 0;
	if (!hCut.empty())
		lastH = hCut.back();
	if (!vCut.empty())
		lastV = vCut.back();


	for (int r = lastH; r < newH; ++r)
	{
		for (int c = 0; c < newV; ++c)
		{

		}
	}

	for (int r = 0; r < newH; ++r)
	{
		for (int c = lastV; c < newV; ++c)
		{

		}
	}

	return true;
}


bool CutIter(vector<int>& hCut, vector<int>& vCut, int hLeft, int vLeft)
{

	if (hLeft == 0 && vLeft == 0)
	{
		return Check(hCut, vCut, R + 1, C + 1);
	}


}



bool Solve()
{
	int chocoCount = 0;
	for (auto column : waffle)
	{
		for (char c : column)
		{
			if (c == '@')
				chocoCount++;
		}
	}

	vector<int> hCut, vCut;
	int h = H;
	int v = V;
	int divide = (h + 1) * (v + 1);
	if (chocoCount % divide != 0)
		return false;

	share = chocoCount / divide;

	return CutIter(hCut, vCut, h, v);
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> R, C, H, V;
		waffle.clear();
		waffle.resize(R);

		for(auto& column : waffle)
			cin >> column;

		bool ret = Solve();
		if (ret)
			cout << "POSSIBLE" << endl;
		else
			cout << "IMPOSSIBLE" << endl;

	}

	return 0;
}
