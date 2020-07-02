
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;


void coutVertorInt(vector<int>& s) {
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void coutVertorIntGrid(vector<vector<int>>& grid) {
	int height = grid.size();
	int width = grid[0].size();
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			cout << grid[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

void coutVertor(vector<string>& s) {
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int res = 0;
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid[0].size(); ++col) {
				if (grid[row][col] == 1) {
					res = max(res, dfs(grid, row, col));
				}
			}
		}
		return res;
	}

	int dfs(vector<vector<int>>& grid, int i, int j) {
		int count = 0;
		stack<int> islands;
		islands.push(i);
		islands.push(j);
		grid[i][j] = 2;
		while (!islands.empty()) {
			int col = islands.top();
			islands.pop();
			int row = islands.top();
			islands.pop();
			
			count++;
			check(grid, islands, row + 1, col);
			check(grid, islands, row, col + 1);
			check(grid, islands, row - 1, col);
			check(grid, islands, row, col - 1);
		}
		return count;
	}

	void check(vector<vector<int>>& grid, stack<int>& islands, int newRow, int newCol) {
		if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()) {
			if (grid[newRow][newCol] == 1) {
				islands.push(newRow);
				islands.push(newCol);
				grid[newRow][newCol] = 2;
			}
		}
	}
};


int main()
{
	Solution test = Solution();
	int res;
	vector<vector<int>> nums;


	nums = {
		{1, 1, 0, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 1, 1},
		{0, 0, 0, 1, 1},
	};

	res = test.maxAreaOfIsland(nums);
	cout << "最大岛屿面积为：" << res;
	cout << endl;


	nums = { {0} };

	res = test.maxAreaOfIsland(nums);
	cout << "最大岛屿面积为：" << res;
	cout << endl;

	nums = {
			{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
			{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
			{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
	};

	res = test.maxAreaOfIsland(nums);
	cout << "最大岛屿面积为：" << res;
}
