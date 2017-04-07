// Mordor2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <stdio.h>
#include <vector>
#define INT_MAX 2147483647
#define MIN(x, y) x < y ? x : y
#define MAX(x, y) x > y ? x : y


struct RMQ // range minimum query
{
	size_t length;
	std::vector<int> rangeMin; //구간별 최소값 트리 (i번째 노드의 자식은 2*i , 2*i + 1)

	// array는 계산하고 싶은 전체 데이터
	RMQ(const std::vector<int>& arr) {
		length = arr.size();
		rangeMin.resize(length * 4);
		init(arr, 0, length - 1, 1);
	}



	int init(const std::vector<int>& arr, int startIdx, int endIdx, int nodeIdx)
	{
		if (startIdx == endIdx)
			return rangeMin[nodeIdx] = arr[startIdx];
		int mid = (startIdx + endIdx) / 2;
		int leftMin = init(arr, startIdx, mid, nodeIdx * 2);
		int rightMin = init(arr, mid + 1, endIdx, nodeIdx * 2 + 1);
		rangeMin[nodeIdx] = leftMin < rightMin ? leftMin : rightMin;
		return rangeMin[nodeIdx];
	}

	int queryRecursive(int startIdx, int endIdx, int nodeIdx, int nodeStartIdx, int nodeEndIdx)
	{
		if (endIdx < nodeStartIdx || nodeEndIdx < startIdx)
			return INT_MAX;

		if (startIdx <= nodeStartIdx && nodeEndIdx <= endIdx)
			return rangeMin[nodeIdx];

		int midIdx = (nodeStartIdx + nodeEndIdx) / 2;
		int leftMin = queryRecursive(startIdx, endIdx, nodeIdx * 2, nodeStartIdx, midIdx);
		int rightMin = queryRecursive(startIdx, endIdx, nodeIdx * 2 + 1, midIdx + 1, nodeEndIdx);
		return leftMin < rightMin ? leftMin : rightMin;
	}

	int query(int leftIdx, int rightIdx)
	{
		return queryRecursive(leftIdx, rightIdx, 1, 0, length - 1);
	}

	int updateRecursive(int newIdx, int newValue, int nodeIdx, int nodeStartIdx, int nodeEndIdx)
	{
		if (newIdx < nodeStartIdx || newIdx > nodeEndIdx)
			return rangeMin[nodeIdx];

		if (nodeStartIdx == nodeEndIdx)
			return rangeMin[nodeIdx] = newValue;

		int midIdx = (nodeStartIdx + nodeEndIdx) / 2;
		int leftUpdate = updateRecursive(newIdx, newValue, nodeIdx * 2, nodeStartIdx, midIdx);
		int rightUpdate = updateRecursive(newIdx, newValue, nodeIdx * 2 + 1, midIdx + 1, nodeEndIdx);

		return rangeMin[nodeIdx] = leftUpdate < rightUpdate ? leftUpdate : rightUpdate;
	}

	int update(int newIdx, int newValue)
	{
		return updateRecursive(newIdx, newValue, 1, 0, length - 1);
	}
};

struct PathInfo
{
	PathInfo() {}

	PathInfo(int _startIdx, int _endIdx, int _minHeight, int _maxHeight)
	{
		startIdx = _startIdx;
		endIdx = _endIdx;
		minHeight = _minHeight;
		maxHeight = _maxHeight;
	}

	int startIdx;
	int endIdx;
	int minHeight;
	int maxHeight;
};


PathInfo NONE_PATH = PathInfo(INT_MAX, -1, INT_MAX, -1);

struct RMQForMordor
{
	size_t length;
	std::vector<PathInfo> rangePathInfo;

	RMQForMordor(const std::vector<int>& heights) {
		length = heights.size();
		rangePathInfo.resize(length * 4);
		init(heights, 0, length - 1, 1);
	}

	PathInfo init(const std::vector<int>& heights, int left, int right, int node)
	{
		PathInfo& currentInfo = rangePathInfo[node];
		if (left == right)
		{
			currentInfo.startIdx = left;
			currentInfo.endIdx = right;
			currentInfo.minHeight = heights[left];
			currentInfo.maxHeight = heights[right];
		}
		else
		{
			int mid = (left + right) / 2;
			PathInfo leftPath = init(heights, left, mid, node * 2);
			PathInfo rightPath = init(heights, mid + 1, right, node * 2 + 1);
			currentInfo = merge(leftPath, rightPath);
		}
		return currentInfo;
	}

	PathInfo queryRecursive(int left, int right, int nodeIdx, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left)
			return NONE_PATH;

		if (left <= nodeLeft && nodeRight <= right)
			return rangePathInfo[nodeIdx];

		int midIdx = (nodeLeft + nodeRight) / 2;
		return merge(queryRecursive(left, right, nodeIdx * 2, nodeLeft, midIdx),
		queryRecursive(left, right, nodeIdx * 2 + 1, midIdx + 1, nodeRight));
	}

	PathInfo query(int leftIdx, int rightIdx)
	{
		return queryRecursive(leftIdx, rightIdx, 1, 0, length - 1);
	}

	PathInfo merge(PathInfo path1, PathInfo path2)
	{
		PathInfo result;
		result.startIdx = MIN(path1.startIdx, path2.startIdx);
		result.endIdx = MAX(path1.endIdx, path2.endIdx);
		result.minHeight = MIN(path1.minHeight, path2.minHeight);
		result.maxHeight = MAX(path1.maxHeight, path2.maxHeight);
		return result;
	}
};



struct MordorTest
{
	int pointCount;
	int pathCount;

	std::vector<int> pointHeights;


	std::vector<PathInfo> pathes;

	void input()
	{
		scanf("%d %d", &pointCount, &pathCount);

		pointHeights;
		pointHeights.resize(pointCount);
		pathes.resize(pathCount);
		for (int i = 0; i < pointCount; ++i)
		{
			int pointHeight = 0;
			scanf("%d ", &pointHeight);
			pointHeights[i] = pointHeight;
		}

		for (int i = 0; i < pathCount; ++i)
		{
			int pathStartIdx = 0;
			int pathEndIdx = 0;
			scanf("%d %d", &pathStartIdx, &pathEndIdx);
			pathes[i].startIdx = pathStartIdx;
			pathes[i].endIdx = pathEndIdx;
		}
	}

	void output()
	{
		RMQForMordor rmq(pointHeights);
		for (PathInfo& path : pathes)
		{
			auto result = rmq.query(path.startIdx, path.endIdx);
			printf("%d\n", result.maxHeight - result.minHeight);
		}
	}
};

int main()
{
	int testCount = 0;
	scanf("%d", &testCount);
	std::vector<MordorTest> tests;
	tests.resize(testCount);
	for (auto& test : tests)
	{
		test.input();
	}
	for (auto& test : tests)
	{
		test.output();
	}

	return 0;
}
