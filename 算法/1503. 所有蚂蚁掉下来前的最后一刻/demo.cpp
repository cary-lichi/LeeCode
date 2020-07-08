class Solution {
public:
	//1503. 所有蚂蚁掉下来前的最后一刻
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		int res = 0;
		if (left.size() > 0) {
			for (int i = 0; i < left.size(); ++i) {
				res = max(left[i], res);
			}
		}
		
		if (right.size() > 0) {
			for (int i = 0; i < right.size(); ++i) {
				res = max(n - right[i], res);
			}
		}
		return res;
	}
};