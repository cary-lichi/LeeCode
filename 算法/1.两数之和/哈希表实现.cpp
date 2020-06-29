#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> map;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			auto iter = map.find(nums[i]);
			if (iter != map.end()) {
				return { i, iter->second };
			}
			int diff = target - nums[i];
			map[diff] = i;

		}
		return {};
	}
};

void coutVertor(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main()
{
	Solution test = Solution();
	vector<int> ivec = { 0,4,0,90 };
	vector<int> res1 = test.twoSum(ivec, 0);
	cout << "测试用例：";
	coutVertor(ivec);
	cout << "输出：";
	coutVertor(res1);

	ivec = { -3,4,3,90 };
	vector<int> res2 = test.twoSum(ivec, 0);
	cout << "测试用例：";
	coutVertor(ivec);
	cout << "输出：";
	coutVertor(res2);

	ivec = { 2,7,3,90 };
	vector<int> res3 = test.twoSum(ivec, 9);
	cout << "测试用例：";
	coutVertor(ivec);
	cout << "输出：";
	coutVertor(res3);
}

