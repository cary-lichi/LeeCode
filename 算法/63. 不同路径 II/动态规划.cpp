
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
		vector<int> list = vector<int>(obstacleGrid[0].size());
		list[0] = (obstacleGrid[0][0] == 0);
		for (int i = 0; i < obstacleGrid.size(); ++i) {
			for (int j = 0; j < obstacleGrid[0].size(); ++j) {
				if (obstacleGrid[i][j] == 1) {
					list[j] = 0;
					continue;
				}
				if (j > 0 && obstacleGrid[i][j - 1] == 0) {
					list[j] += list[j - 1];
				}
			}
		}
		return list[obstacleGrid[0].size() - 1];
	}
	
};

int main()
{
	Solution test = Solution();
	int res;
	vector<vector<int>> list;

	list = {
		{ 0,1 },
	};
	res = test.uniquePathsWithObstacles(list);
	cout << res << endl;

	list = {
		{ 0,0,0 },
		{ 0,1,0 },
		{ 0,0,0 },
	};
	res = test.uniquePathsWithObstacles(list);
	cout << res << endl;
}