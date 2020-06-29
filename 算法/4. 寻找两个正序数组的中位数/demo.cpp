
#include <iostream>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) {
			return findMedianSortedArrays(nums2, nums1);
		}
		int l1 = nums1.size();
		int l2 = nums2.size();

		int mid = (l1 + l2 + 1) / 2;

		int left = 0, right = l1;
		while (left < right) {

			int mid1 = (left + right + 1) / 2;
			int mid2 = mid - mid1;

			if (nums1[mid1 - 1] > nums2[mid2]) {
				right = mid1 - 1;
			}
			else {
				left = mid1;
			}
		}

		int mid1 = left;
		int mid2 = mid - mid1;
		int left1 = mid1 == 0 ? INT32_MIN : nums1[mid1 - 1];
		int right1 = mid1 == l1 ? INT32_MAX : nums1[mid1];
		int left2 = mid2 == 0 ? INT32_MIN : nums2[mid2 - 1];
		int right2 = mid2 == l2 ? INT32_MAX : nums2[mid2];

		if ((l1 + l2) % 2==1) {
			int max = left1 > left2 ? left1 : left2;
			return max;
		}
		else {
			double maxLeft = left1 > left2 ? left1 : left2;
			double minRight = right1 < right2 ? right1 : right2;
			return (maxLeft + minRight) / 2;
		}

		return 1.0;
	}
};

void coutVector(vector<int> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

int main()
{
	Solution test = Solution();
	vector<int> nums1 = { 100000};
	vector<int> nums2 = { 100001};
	double res = test.findMedianSortedArrays(nums1, nums2);
	coutVector(nums1);
	coutVector(nums2);
	cout << "中位数为" << res << endl;
}