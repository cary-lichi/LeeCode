class Solution {
public:
	//1502. 判断能否形成等差数列
	bool canMakeArithmeticProgression(vector<int>& arr) {
		if (arr.size() == 0) {
			return false;
		}
		if (arr.size() == 1) {
			return true;
		}
		sort(arr.begin(), arr.end());
		int n = arr[1] - arr[0];
		for (int i = 0; i < arr.size() - 1; ++i) {
			if (arr[i] != arr[i + 1] - n) {
				return false;
			}
		}
		return true;
	}
};