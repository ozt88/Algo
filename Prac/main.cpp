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

vector<int> fixedSwitchKey = { 11, 8, 13, 10, 6, 7, 5, 1, 0, 3 };

vector<vector<int>> fixedSwitches =
{
	{ 3, 7, 9, 11 },  // only 11
	{ 6, 7, 8, 10, 12 }, //only 8, 12
	{ 3, 4, 5, 9, 13 }, // only 13
	{4, 10, 14, 15}, //only 10
	{ 0, 4, 5, 6, 7 }, //only 6
	{ 4, 5, 7, 14, 15 }, //only  7
	{ 1, 2, 3, 4, 5 }, //only 5
	{0, 1, 2}, //only 1
	{ 0, 2, 14, 15 }, // only 0
	{ 3, 14, 15 }, // only 3
};

int SolveLikeSudoku(vector<int>& input)
{
	vector<int> clocks;
	for (auto in : input)
		clocks.push_back((in / 3) % 4);

	if (input[8] != input[12])
		return -1;
	
	int ret = 0;
	for (int i = 0; i < fixedSwitchKey.size(); ++i)
	{
		int count = (4 - clocks[fixedSwitchKey[i]]) % 4;
		ret += count;
		for (int idx : fixedSwitches[i])
		{
			clocks[idx] = (clocks[idx] + count) % 4;
		}
	}

	for (int c : clocks)
	{
		if (c % 4)
			return -1;
	}

	return ret;
}


void TurnSwitch(vector<int>& clock, int index, int count)
{
	for (auto idx : fixedSwitches[index])
		clock[idx] = (clock[idx] + count) % 4;
}

//10 switch & max 4 case per switch = 4^10 = 1048576 case
int SolveBrutalIter(vector<int>& clock, int switchIndex)
{
	if (switchIndex >= 10)
		return all_of(clock.begin(), clock.end(), [](int x) { return x == 0; }) ? 0 : -1;

	int ret = 0;
	for (int count = 0; count < 4; ++count)
	{
		TurnSwitch(clock, switchIndex, count);
		ret = SolveBrutalIter(clock, switchIndex + 1);
		if (ret >= 0)
			return ret + count;

		TurnSwitch(clock, switchIndex, 4 - count);
	}
	return -1;
}


int SolveBrutal(vector<int>& input)
{
	vector<int> clocks;
	for (auto in : input)
		clocks.push_back((in / 3) % 4);

	return SolveBrutalIter(clocks, 0);
}

int main()
{
	int C;
	cin >> C;

	for (int c = 0; c < C; ++c)
	{
		vector<int> input(16, 0);
		for (auto& i : input)
		{
			cin >> i;
		}
		cout << SolveBrutal(input) << endl;
	}

	return 0;
}
