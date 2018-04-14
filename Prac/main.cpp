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

bool Check(vector<int>& hCut, vector<int>& vCut, int newH, int newV)
{
	int lastH = 0;
	int lastV = 0;
	if (!hCut.empty())
		lastH = hCut.back();
	if (!vCut.empty())
		lastV = vCut.back();


	//vCheck
	vector<int> vCheck(vCut.size() + 1);
	auto checkVIt = vCut.begin();
	for (int r = lastH; r < newH; ++r)
	{
		for (int c = 0; c < newV; ++c)
		{
			int checkV;
			if (checkVIt == vCut.end())
				checkV = newV;
			else
				checkV = *checkVIt;

			if (c < checkV)
			{
				if(waffle[r][c] != '@')
					vCheck[vCut.begin() - checkVIt]++;
			}
			else
				checkVIt++;
		}
	}

	for (auto checkShare : vCheck)
	{
		if (checkShare != share)
			return false;
	}


	//cCheck
	vector<int> hCheck(hCut.size() + 1);
	auto checkHIt = hCut.begin();

	for (int r = 0; r < newH; ++r)
	{
		for (int c = lastV; c < newV; ++c)
		{

			int checkH;
			if (checkHIt == hCut.end())
				checkH = newH;
			else
				checkH = *checkHIt;

			if (c < checkH)
			{
				if(waffle[r][c] == '@')
					hCheck[hCut.begin() - checkHIt]++;
			}
			else
				checkHIt++;
		}
	}

	for (auto checkShare : hCheck)
	{
		if (checkShare != share)
			return false;
	}

	return true;
}


bool CutIter(vector<int>& hCut, vector<int>& vCut, int hLeft, int vLeft)
{
	if (hLeft == 0 && vLeft == 0)
	{
		return Check(hCut, vCut, R + 1, C + 1);
	}

	int lastH = 0;
	int lastV = 0;
	if (!hCut.empty())
		lastH = hCut.back();
	if (!vCut.empty())
		lastV = vCut.back();

	for (int r = lastH + 1; r <= R; ++r)
	{
		for (int c = lastV + 1; c <= C; ++c)
		{
			if (Check(hCut, vCut, r, c))
			{

			}
		}
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


bool CheckSmall(int h, int v)
{
	vector<int> check(4);
	for (int r = 0; r < R; ++r)
	{
		for (int c = 0; c < C; ++c)
		{
			if (waffle[r][c] != '@')
				continue;

			if (r < h && c < v)
				check[0]++;
			else if (r < h && c >= v)
				check[1]++;
			else if (r >= h && c < v)
				check[2]++;
			else if (r >= h && c >= v)
				check[3]++;
			else
				assert(false);
		}
	}

	for (auto checkSum : check)
	{
		if (checkSum != share)
			return false;
	}
	return true;
}

bool SolveSmall()
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

	for (int h = 1; h < R ; ++h)
	{
		for (int v = 1; v < C; ++v)
		{
			if (CheckSmall(h, v))
				return true;
		}
	}

	return false;
}


int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> R >> C >> H >> V;
		waffle.clear();
		waffle.resize(R);

		for(auto& column : waffle)
			cin >> column;

		bool ret = SolveSmall();
		if (ret)
			cout << "Case #" << i + 1<< ": POSSIBLE" << endl;
		else
			cout << "Case #" << i + 1<< ": IMPOSSIBLE" << endl;

	}

	return 0;
}
