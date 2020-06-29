
#include <iostream>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int max = 0;
	int start = 0;
	string longestPalindrome(string s) {
		if (s.size() == 0) {
			return "";
		}
		max = 1;
		start = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			checkPalindrome(s, i, i);
			checkPalindrome(s, i, i + 1);
		}
		return s.substr(start, max);
	}


	void checkPalindrome(string s, int left, int right) {
		if (s[left] != s[right]) {
			return;
		}
		while (true) {
			if (left <= 0 || right >= s.size()) {
				break;
			}

			if (s[left - 1] != s[right + 1]) {
				break;
			}

			--left;
			++right;
		}
		int length = right - left + 1;
		if (max < length) {
			max = length;
			start = left;
		}
	}
};

int main()
{
	Solution test = Solution();
	string s;
	string res;

	s = "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir";
	res = test.longestPalindrome(s);

	cout << "输入：" << s << endl;
	cout << "输出最长的回文：" << res << endl;

	s = "";
	res = test.longestPalindrome(s);

	cout << "输入：" << s << endl;
	cout << "输出最长的回文：" << res << endl;

	s = "a";
	res = test.longestPalindrome(s);

	cout << "输入：" << s << endl;
	cout << "输出最长的回文：" << res << endl;

	s = "asfddsa";
	res = test.longestPalindrome(s);

	cout << "输入：" << s << endl;
	cout << "输出最长的回文：" << res << endl;

	s = "babad";
	res = test.longestPalindrome(s);

	cout << "输入：" << s << endl;
	cout << "输出最长的回文：" << res << endl;

	s = "cbbd";
	res = test.longestPalindrome(s);

	cout << "输入：" << s << endl;
	cout << "输出最长的回文：" << res << endl;

}
