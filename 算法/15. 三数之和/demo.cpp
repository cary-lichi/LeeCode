
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
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		if (n < 3) {
			return {};
		}
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < n - 2; ++i) {
			if (i > 0 && nums[i - 1] == nums[i]) {
				continue;
			}
			if (nums[i] > 0) {
				break;
			}
			int left = i + 1;
			int right = n - 1;
			while (left < right) {
				int num = nums[i] + nums[left] + nums[right];
				if (num == 0) {
					res.push_back({ nums[i], nums[left], nums[right] });
				}

				if (num > 0) {
					--right;
					while (left < right && nums[right] == nums[right + 1]) {
						--right;
					}
				}
				else {
					++left;
					while (left < right && nums[left] == nums[left - 1]) {
						++left;
					}
				}
			}
		}
		return res;
	}
};


int main()
{
	Solution test = Solution();
	vector<vector<int>> res;
	vector<int> nums;

	nums = { -1,0,1,2,-1,-4 };
	res = test.threeSum(nums);

	for (int i = 0; i < res.size(); i++) {
		coutVertorInt(res[i]);
	}
	cout << endl;

	nums = { 0, 0, 0, 0, 0, };
	res = test.threeSum(nums);

	for (int i = 0; i < res.size(); i++) {
		coutVertorInt(res[i]);
	}

	cout << endl;

	nums = { -1, 0, 1, 2, -1, -4, 0, 0, 2, -4, 8, 5,-5 };
	res = test.threeSum(nums);

	for (int i = 0; i < res.size(); i++) {
		coutVertorInt(res[i]);
	}
}
