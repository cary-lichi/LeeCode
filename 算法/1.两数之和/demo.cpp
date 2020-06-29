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
		vector<int> vecTest;
		for (int i = 0; i < nums.size(); i++)
		{
			int a = nums[i];

			for (int i = 0; i < vecTest.size(); i++)
			{
				int b = vecTest[i];
				if (a + b == target)
				{
					return { a, b };
				}
			}
			vecTest.push_back(a);
		}
		return {};
	};
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

