
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		int n = s.size();
		int min = n > numRows ? numRows : n;
		vector<string> rows = vector<string>(min);
		int row = 0;
		int dir = 1;
		for (int i = 0; i < n; ++i) {
			if (row == 0) {
				dir = 1;
			}
			else if(row== numRows-1)
			{
				dir = -1;
			}
			rows[row] += s[i];
			row += dir;
		}
		string res;
		for (int i = 0; i < rows.size(); ++i) {
			res += rows[i];
		}
		return res;
	}
};

int main()
{
	Solution test = Solution();
	string res;
	res = test.convert("LEETCODEISHIRING", 3);
	cout << res << endl;

	res = test.convert("", 1);
	cout << res << endl;

	res = test.convert("L", 1);
	cout << res << endl;
}
