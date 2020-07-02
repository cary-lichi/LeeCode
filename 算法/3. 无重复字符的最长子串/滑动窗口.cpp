
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        int left = 0;
        int res = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = left; j < i; ++j) {
                if (s[i] == s[j]) {
                    int length = i - left;
                    if (length > res) {
                        res = length;
                    }
                    left = j + 1;
                }
            }
            int length = i - left+1;
            if (length > res) {
                res = length;
            }
        }
        return res;
    }
};

int main()
{
	Solution test = Solution();
    int max;

    max = test.lengthOfLongestSubstring("dvdf");
    cout << max << endl;

    max = test.lengthOfLongestSubstring("au");
    cout << max << endl;

    max = test.lengthOfLongestSubstring("bbbbb");
    cout << max << endl;

    max = test.lengthOfLongestSubstring("abcdabcdefbb");
    cout << max << endl;
}
