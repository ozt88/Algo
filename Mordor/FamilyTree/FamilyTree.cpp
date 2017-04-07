#include <stdio.h>
#include <vector>

#define MIN(x, y) x < y ? x : y
#define MAX(x, y) x > y ? x : y


struct FamilyTreeNode
{
	FamilyTreeNode(FamilyTreeNode* _parent, int _height, int _index, const std::vector<int>& _inputs)
	{
		parent = _parent;
		height = _height;
		originalIndex = _index;
		for (int idx = 0; idx < _inputs.size(); ++idx)
		{
			int input = _inputs[idx];
			if (_index == input)
				children.push_back(new FamilyTreeNode(this, height + 1, idx + 1, _inputs));
		}
	}

	~FamilyTreeNode()
	{
		for (auto child : children)
			delete child;
	}

	void PrintTreeNode()
	{
		printf("%d%t", originalIndex);
		for (FamilyTreeNode* child : children)
		{
			child->PrintTreeNode();
		}
	}

	void FamilyOrderedListIterate(std::vector<FamilyTreeNode*>& list)
	{
		if(children.size() == 0)
			list.push_back(this);
		else
			for (auto& child : children)
				child->FamilyOrderedListIterate(list);

		if (parent != nullptr)
			list.push_back(parent);
	}

	int originalIndex = -1;
	FamilyTreeNode* parent = nullptr;
	std::vector<FamilyTreeNode*> children;
	int height = 0;
};


struct RMQForFamily // range minimum query
{
	size_t length;
	std::vector<FamilyTreeNode*> rangeCommonAncient; //구간별 최고 공통 조상 (i번째 노드의 자식은 2*i , 2*i + 1)

	RMQForFamily()
	{
	}

											   // array는 계산하고 싶은 전체 데이터
	RMQForFamily(const std::vector<FamilyTreeNode*>& arr) {
		length = arr.size();
		rangeCommonAncient.resize(length * 4);
		init(arr, 0, length - 1, 1);
	}

	FamilyTreeNode* init(const std::vector<FamilyTreeNode*>& arr, int startIdx, int endIdx, int nodeIdx)
	{
		if (startIdx == endIdx)
			return rangeCommonAncient[nodeIdx] = arr[startIdx];
		int mid = (startIdx + endIdx) / 2;
		auto leftCommon = init(arr, startIdx, mid, nodeIdx * 2);
		auto rightCommon = init(arr, mid + 1, endIdx, nodeIdx * 2 + 1);
		rangeCommonAncient[nodeIdx] = leftCommon->height < rightCommon->height ? leftCommon : rightCommon;
		return rangeCommonAncient[nodeIdx];
	}

	FamilyTreeNode* queryRecursive(int startIdx, int endIdx, int nodeIdx, int nodeStartIdx, int nodeEndIdx)
	{
		if (endIdx < nodeStartIdx || nodeEndIdx < startIdx)
			return nullptr;

		if (startIdx <= nodeStartIdx && nodeEndIdx <= endIdx)
			return rangeCommonAncient[nodeIdx];

		int midIdx = (nodeStartIdx + nodeEndIdx) / 2;
		FamilyTreeNode* leftCommon = queryRecursive(startIdx, endIdx, nodeIdx * 2, nodeStartIdx, midIdx);
		FamilyTreeNode* rightCommon = queryRecursive(startIdx, endIdx, nodeIdx * 2 + 1, midIdx + 1, nodeEndIdx);
		if (leftCommon == nullptr)
			return rightCommon;
		
		if (rightCommon == nullptr)
			return leftCommon;

		return leftCommon->height < rightCommon->height ? leftCommon : rightCommon;
	}

	FamilyTreeNode* query(int leftIdx, int rightIdx)
	{
		return queryRecursive(leftIdx, rightIdx, 1, 0, length - 1);
	}
};


struct FamilyTree
{
	FamilyTree(const std::vector<int>& inputs)
	{
		root = new FamilyTreeNode(nullptr, 0, 0, inputs);
		root->FamilyOrderedListIterate(orderedFamily);
		orderList.resize(inputs.size() + 1);
		for (int i = 0 ; i < orderedFamily.size(); ++i)
		{
			orderList[orderedFamily[i]->originalIndex] = i;
		}
		
		rmq = new RMQForFamily(orderedFamily);
	}

	~FamilyTree()
	{
		delete root;
	}

	int FigureStepHeight(int firstIdx, int secondIdx)
	{
		int firstIndexOrder = orderList[firstIdx];
		int secondIndexOrder = orderList[secondIdx];

		auto firstNode = orderedFamily[firstIndexOrder];
		auto secondNode = orderedFamily[secondIndexOrder];
		auto commonNode = rmq->query(MIN(firstIndexOrder, secondIndexOrder), MAX(firstIndexOrder, secondIndexOrder));

		return (firstNode->height + secondNode->height) - commonNode->height * 2;
	}

	FamilyTreeNode* root = nullptr;
	std::vector<FamilyTreeNode*> orderedFamily;
	std::vector<int> orderList;
	RMQForFamily* rmq = nullptr;
};

struct FamilyTreeTest
{
	FamilyTree* tree;
	std::vector < std::pair<int, int >> problems;

	~FamilyTreeTest()
	{
		delete tree;
	}

	void input()
	{
		int nodeCount;
		int problemCount;

		scanf("%d %d", &nodeCount, &problemCount);
		nodeCount--;
		std::vector<int> treeInputs;
		treeInputs.resize(nodeCount);
		problems.resize(problemCount);

		for (int i = 0; i < nodeCount; ++i)
		{
			int pointHeight = 0;
			scanf("%d ", &pointHeight);
			treeInputs[i] = pointHeight;
		}

		for (int i = 0; i < problemCount; ++i)
		{
			int pathStartIdx = 0;
			int pathEndIdx = 0;
			scanf("%d %d", &pathStartIdx, &pathEndIdx);
			problems[i].first = pathStartIdx;
			problems[i].second = pathEndIdx;
		}
		tree = new FamilyTree(treeInputs);
	}

	void output()
	{
		for (auto& problem : problems)
		{
			int stepHeight = tree->FigureStepHeight(problem.first, problem.second);
			printf("%d\n", stepHeight);
		}
	}
};


int main()
{
	int testCount = 0;
	scanf("%d", &testCount);
	for (int i = 0; i < testCount; ++i)
	{
		FamilyTreeTest test;
		test.input();
		test.output();
	}
}
