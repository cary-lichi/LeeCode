
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int n = s1.size();
		int m = s2.size();
		if (n > m) {
			return false;
		}
		if (n == 0) {
			return true;
		}
		vector<int> list1 = vector<int>(26);
		vector<int> list2 = vector<int>(26);

		int count = 0;
		for (int i = 0; i < n; ++i) {
			++list1[s1[i] - 'a'];
			++list2[s2[i] - 'a'];
		}

		for (int i = 0; i < 26; i++) {
			if (list1[i] != list2[i]) {
				++count;
			}
		}

		if (count == 0) {
			return true;
		}

		for (int i = n; i < m; ++i) {
			int left = s2[i - n] - 'a';
			int right = s2[i] - 'a';
			if (list1[left] == list2[left]) {
				++count;
			}
			else if (list1[left] == list2[left] - 1)
			{
				--count;
			}
			--list2[left];

			if (list1[right] == list2[right]) {
				++count;
			}
			else if (list1[right] == list2[right] + 1)
			{
				--count;
			}
			++list2[right];

			if (count == 0) {
				return true;
			}
		}

		return count == 0;
	}
};

int main()
{
	Solution test = Solution();
	bool res;

	res = test.checkInclusion("abc", "a");
	cout << res << endl;

	res = test.checkInclusion("abc", "bbbca");
	cout << res << endl;

	res = test.checkInclusion("adc", "dcda");
	cout << res << endl;

	res = test.checkInclusion("ab", "eidbaooo");
	cout << res << endl;

}
