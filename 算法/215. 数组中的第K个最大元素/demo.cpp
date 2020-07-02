
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
	int findKthLargest(vector<int>& nums, int k) {
		return select(nums, 0, nums.size() - 1, nums.size() - k);
	}

	int select(vector<int>& nums, int left, int right, int k) {
		if (left == right) {
			return nums[k];
		}
		int mid = rand() % (right - left + 1) + left;

		int index = partition(nums, left, right, mid);

		if (index < k) {
			return select(nums, index + 1, right, k);
		}
		else if (index > k) {
			return select(nums, left, index - 1, k);
		}
		else {
			return nums[k];
		}
	}

	int partition(vector<int>& nums, int left, int right, int mid) {
		int index = left;
		int midvalue = nums[mid];
		swap(nums[mid], nums[right]);
		for (int i = left; i < right; ++i) {
			if (nums[i] < midvalue) {
				swap(nums[i], nums[index]);
				++index;
			}
		}
		swap(nums[index], nums[right]);
		return index;
	}
};

int main()
{
	Solution test = Solution();
	int res;
	vector<int> nums;

	nums = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	res = test.findKthLargest(nums, 4);
	cout << res << endl;

	nums = { 3,2,1,5,6,4 };
	res = test.findKthLargest(nums, 2);
	cout << res << endl;


}
