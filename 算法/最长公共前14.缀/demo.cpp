
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }

        int min = INT32_MAX;
        for (int i = 0; i < strs.size(); ++i) {
            int n = strs[i].size();
            if (n < min) {
                min = n;
            }
        }
        if (min == 0) {
            return "";
        }
        string res = "";
        for (int i = 0; i < min; ++i) {
            char temp = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != temp) {
                    return res;
                }
            }
            res += temp;
        }
        return res;
    }
};

int main()
{
	Solution test = Solution();
    string max;
    vector<string> list = { "flower","flow","flight" };
    max = test.longestCommonPrefix(list);
    cout << max << endl;

}
