
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

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() <= 1) {
			return nums.size();
		}
		unordered_set<int> set;
		for (int i = 0; i < nums.size(); ++i) {
			set.insert(nums[i]);
		}
		int res = 0;
		for (int num : set) {
			int count = 1;
			if (set.count(num + 1) == 1) {
				continue;
			}
			while (true) {
				if (set.count(num - 1) == 1) {
					--num;
					++count;
				}
				else
				{
					break;
				}
			}
			res = max(res, count);
		}
		return res;
	}
};

int main()
{
	Solution test = Solution();
	int res;
	vector<int> nums = { 100, 4, 200, 1, 3, 2 };
	res = test.longestConsecutive(nums);
	cout << res <<endl;
}