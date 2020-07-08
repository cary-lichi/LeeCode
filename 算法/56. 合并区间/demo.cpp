
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
	//56. 合并区间
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		for (int i = 0; i < intervals.size(); ++i) {
			int left = intervals[i][0];
			int right = intervals[i][1];
			if (res.empty() || res.back()[1] < left) {
				res.push_back({ left,right });
			}
			else {
				res.back()[1] = max(right, res.back()[1]);
			}
		}
		return res;
	}
};

int main()
{
	Solution test = Solution();
	vector<vector<int>> res;
	vector<vector<int>> list;

	list = {
		{ 2,3 },
		{ 4, 5},
		{ 6, 7},
		{ 8, 9},
		{ 1, 10},
	};
	res = test.merge(list);
	coutVertorIntGrid(res);

	list = {
		{ 1,4 },
		{ 2,3 },
	};
	res = test.merge(list);
	coutVertorIntGrid(res);


	list = {
		{ 8, 16 },
		{ 1, 3 },
		{ 2, 6 },
		{ 15, 18 },
	};
	res = test.merge(list);
	coutVertorIntGrid(res);
}