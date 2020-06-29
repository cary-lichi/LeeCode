#include <iostream>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> map;
		int n = s.size();
		int left = -1;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				map.erase(s[i - 1]);
			}
			while (left + 1 < n && !map.count(s[left + 1])) {
				map.insert(s[left + 1]);
				++left;
			}
			int a = left - i + 1;
			res = res < a ? a : res;
		}
		return res;
	}
};

int main()
{
	Solution test = Solution();
	int max = test.lengthOfLongestSubstring("abcabcbb");
	cout << max << endl;

	max = test.lengthOfLongestSubstring("bbbbb");
	cout << max << endl;

	max = test.lengthOfLongestSubstring("abcabcbb");
	cout << max << endl;
}