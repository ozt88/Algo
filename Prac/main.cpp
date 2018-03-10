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
string wildCard, fileName;

bool checkWildCard(int wildCardIdx, int fileNameIdx)
{
	if (wildCardIdx == wildCard.length() && fileNameIdx == fileName.length())
		return true;

	if (wildCardIdx > wildCard.length() || fileNameIdx > fileName.length())
		return false;

	int ret = cache[wildCardIdx][fileNameIdx];
	if (ret != -1)
		return ret;

	ret = false;

	if (wildCardIdx < wildCard.length() && fileNameIdx < fileName.length() &&
		(wildCard[wildCardIdx] == '?' || wildCard[wildCardIdx] == fileName[fileNameIdx]))
	{
		ret = checkWildCard(wildCardIdx + 1, fileNameIdx + 1);
	}
	else if (wildCard[wildCardIdx] == '*')
	{
		ret = checkWildCard(wildCardIdx + 1, fileNameIdx) || checkWildCard(wildCardIdx, fileNameIdx + 1);
	}

	cache[wildCardIdx][fileNameIdx] = ret;
	return ret;
}

int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		int N;
		vector<string> rets;
		cin >> wildCard >> N;
		for (int j = 0; j < N; ++j)
		{
			memset(cache, -1, sizeof(cache));
			cin >> fileName;
			if (checkWildCard(0, 0))
				rets.push_back(fileName);
		}

		sort(rets.begin(), rets.end());
		for (auto ret : rets)
			cout << ret << endl;
	}

	return 0;
}
