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

int FindConnectedRectSize(int left, int right, int center, const vector<int>& fences)
{
	int leftCursor = center;
	int rightCursor = center + 1;
	int minHeight = min(fences[leftCursor], fences[rightCursor]);
	int maxSize = 0;

	do
	{
		while (leftCursor > left && fences[leftCursor - 1] >= minHeight)
			leftCursor--;

		while (rightCursor < right && fences[rightCursor + 1] >= minHeight)
			rightCursor++;

		int newSize = minHeight * (rightCursor - leftCursor + 1);
		maxSize = max(maxSize, newSize);

		int leftHeight = leftCursor > left ? fences[leftCursor - 1] : 0;
		int rightHeight = rightCursor < right ? fences[rightCursor + 1] : 0;
		minHeight = max(leftHeight, rightHeight);

	} while (leftCursor > left || rightCursor < right);

	return maxSize;
}

int FindBiggestRectSize(int left, int right, const vector<int>& fences)
{
	if (left == right)
		return fences[left];

	int center = left + ((right - left) / 2);
	int leftBiggest = FindBiggestRectSize(left, center, fences);
	int rightBiggest = FindBiggestRectSize(center + 1, right, fences);
	int connectedBiggest = FindConnectedRectSize(left, right, center, fences);
	return max(max(leftBiggest, rightBiggest), connectedBiggest);
}

int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		int N;
		cin >> N;
		vector<int> fences(N);
		for (auto& fence : fences)
		{
			cin >> fence;
		}
		cout << FindBiggestRectSize(0, fences.size() - 1, fences) << endl;
	}

	return 0;
}
