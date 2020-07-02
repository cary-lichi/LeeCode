
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
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return -1;
		}
		if (nums.size() == 1) {
			return nums[0] == target ? 0 : -1;
		}
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[left] == target) {
				return left;
			}
			if (nums[right] == target) {
				return right;
			}
			if (nums[left] <= nums[mid]) {
				if (nums[left] <= target && nums[mid] >= target) {
					right = mid;
				}
				else
				{
					left = mid + 1;
				}
			}else {
				if (nums[right] >= target && nums[mid] <= target) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}
		}
		return -1;
	}
};


int main()
{
	Solution test = Solution();
	int res;
	vector<int> nums;

	nums = { 1,3 };
	res = test.search(nums, 0);

	cout << res << endl;

	nums = { 2 };
	res = test.search(nums, 2);

	cout << res << endl;

	nums = { 4,5,6,7,0,1,2 };
	res = test.search(nums, 2);

	cout << res << endl;

	res = test.search(nums, 3);

	cout << res << endl;

	nums = { 4,5,6,7,8,1,2,3 };
	res = test.search(nums, 3);

	cout << res << endl;
}
