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


bool Check(int x, int y, const vector<pair<int, int>>& candidate, const vector<vector<char>>& board)
{
	for (auto& checkDir : candidate)
	{
		int checkX = x + checkDir.first;
		int checkY = y + checkDir.second;

		if(checkX >= board.size() || checkY >= board[checkX].size() || board[checkX][checkY] != '.')
			return false;
	}

	return true;
}

void Mark(int x, int y, const vector<pair<int, int>>& candidate, vector<vector<char>>& board)
{
	for (auto& checkDir : candidate)
		board[x + checkDir.first][y + checkDir.second] = '#';
}

void Unmark(int x, int y, const vector<pair<int, int>>& candidate, vector<vector<char>>& board)
{
	for (auto& checkDir : candidate)
		board[x + checkDir.first][y + checkDir.second] = '.';
}

bool CheckWholeBoardComplete(const vector<vector<char>>& board, const int H, const int W)
{
	for(int h = 0; h < H; ++h)
	{
		for (int w = 0; w < W; ++w)
		{
			if(board[w][h] == '.')
				return false;
		}
	}
	return true;
}

int Iter(int idx, vector<vector<char>>& board, const int H, const int W)
{
	if(CheckWholeBoardComplete(board, H, W))
		return 1;

	if (idx >= H * W)
		return 0;

	static const vector<vector<pair<int, int>>> candidates = { {{0, 0}, {0, 1}, {1, 0}}, {{0, 0}, {1, 0}, {1, 1}},  {{0, 0}, {0, 1}, {1, 1}}, {{0, 1}, {1, 0}, {1, 1}}, {}};
	int x = idx % W, y = idx / W;
	int result = 0;
	for (auto& candidate : candidates)
	{
		if (Check(x, y, candidate, board))
		{
			Mark(x, y, candidate, board);
			if(board[x][y] == '#')
				result += Iter(idx + 1, board, H, W);
			Unmark(x, y, candidate, board);
		}
	}

	return result;
}

int Solve(vector<vector<char>>& board, const int H, const int W)
{
	return Iter(0, board, H, W);
}

int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		int H, W;
		cin >> H >> W;
		vector<vector<char>> board(W, vector<char>(H));
		for (int h = 0; h < H; ++h)
		{
			for (int w = 0; w < W; ++w)
			{
				cin >> board[w][h];
			}
		}
		int result = Solve(board, H, W);
		cout <<  result << endl;
	}

	return 0;
}
