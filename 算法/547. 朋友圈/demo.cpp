
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
	int findCircleNum(vector<vector<int>>& M) {
		int res = 0;
		vector<int> temp = vector<int>(M.size());
		for (int i = 0; i < M.size(); ++i) {
			if (dfs(M, temp, i)) {
				++res;
			}
		}
		return res;
	}

	bool dfs(vector<vector<int>>& M, vector<int>& temp, int i) {
		if (temp[i] == 1) {
			return false;
		}
		temp[i] = 1;
		
		bool res = false;
		for (int j = 0; j < M.size(); ++j) {
			if (M[i][j] == 1) {
				res = true;
				dfs(M, temp, j);
			}
		}
		return res;
	}
};

int main()
{
	Solution test = Solution();
	int res;
	vector<vector<int>> list;
	list = {
		{ 1, 0, 0, 1 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 1 }
	};
	res = test.findCircleNum(list);
	cout << res << endl;
	cout << endl;

	list = {
	   { 1, 1, 0 },
	   { 1, 1, 0 },
	   { 0, 0, 1 }
	};
	res = test.findCircleNum(list);
	cout << res << endl;
}