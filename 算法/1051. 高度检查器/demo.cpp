
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int heightChecker(vector<int>& heights) {
		vector<int> list = heights;
		sort(list.begin(), list.end());
		int res = 0;
		for (int i = 0; i < heights.size(); i++) {
			if (list[i] != heights[i]) {
				++res;
			}
		}
		return res;
	}
};

void couVector(vector<int> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i];
	}
	cout << endl;
}

int main()
{
	Solution test = Solution();
	int res;
	vector<int> list;

	list = { 1,1,4,2,1,3 };
	res = test.heightChecker(list);
	cout << "输入数组：";
	couVector(list);
	cout << "输出：" << res;
	cout << endl;

	list = { 5,1,2,3,4 };
	res = test.heightChecker(list);
	cout << "输入数组：";
	couVector(list);
	cout << "输出：" << res;
	cout << endl;
}
