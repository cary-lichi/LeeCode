
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void coutVertorInt(vector<int>& s) {
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void coutVertor(vector<string>& s) {
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void coutVertorIntGrid(vector<vector<int>>& grid) {

	for (int i = 0; i < grid.size(); ++i) {
		cout << "[" << grid[i][0] << "," << grid[i][1] << "] ";
	}
	cout << endl;
}

class Solution {
public:
	//63. 不同路径 II
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		return dfs(obstacleGrid, 0, 0);
	}

	int dfs(vector<vector<int>>& obstacleGrid, int i, int j) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (i >= m || j >= n) {
			return 0;
		}
		if (obstacleGrid[i][j] == 1) {
			return 0;
		}
		if (i == m - 1 && j == n - 1) {
			return 1;
		}
		int num = 0;
		num += dfs(obstacleGrid, i + 1, j);
		num += dfs(obstacleGrid, i, j + 1);
		return num;
	}
};
int main()
{
	Solution test = Solution();
	int res;
	vector<vector<int>> list;

	list = {
		{ 0,0,0 },
		{ 0,0,0 },
		{ 0,0,0 },
	};
	res = test.uniquePathsWithObstacles(list);
	cout << res << endl;
}