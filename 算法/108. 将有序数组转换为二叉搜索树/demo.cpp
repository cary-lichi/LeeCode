
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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) {
			return NULL;
		}
		return buildBST(nums, 0, nums.size() - 1);
	}

	TreeNode* buildBST(vector<int>& nums,int left,int right) {
		if (left > right) {
			return NULL;
		}
		int mid = left + (right - left) / 2;
		TreeNode* tree = new TreeNode(nums[mid]);
		tree->left = buildBST(nums, left, mid - 1);
		tree->right = buildBST(nums, mid + 1, right);
		return tree;
	}
};

void coutTreeNode(TreeNode s) {
	vector<TreeNode> list;
	list.push_back(s);
	while(!list.empty()) {

	}
	cout << endl;
}

int main()
{
	Solution test = Solution();
	TreeNode* res;
	vector<int> nums = { -10,-3,0,5,9 };
	res = test.sortedArrayToBST(nums);
	cout << "生成的树为";
}

