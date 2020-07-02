
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

void coutVertor(vector<string>& s) {
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int left = matrix[0][0];
		int right = matrix[n - 1][n - 1];
		while (left < right) {
			int mid = left + ((right - left) >> 1);
			int count = ckeck(matrix, mid);
			if (count >= k) {
				right = mid;
			}
			else if (count < k) {
				left = mid + 1;
			}
		}
		return left;
	}

	int ckeck(vector<vector<int>>& matrix, int mid) {
		int n = matrix.size();
		int row = n - 1;
		int col = 0;
		int count = 0;
		while (row >= 0 && col < n) {
			if (matrix[row][col] > mid) {
				--row;
			}
			else
			{
				count += row + 1;
				++col;
			}
		}
		return count;
	}
};


int main()
{
	Solution test = Solution();
	//string res;
	int res;
	vector<vector<int>> matrix;
	matrix = {
		{1,2},
		{1,3},
	};
	res = test.kthSmallest(matrix, 3);
	cout << res;

	cout << endl;
	matrix = {
		{1,5,11},
		{4,12,13},
		{9,13,15},
	};
	res = test.kthSmallest(matrix, 8);
	cout << res;
}
