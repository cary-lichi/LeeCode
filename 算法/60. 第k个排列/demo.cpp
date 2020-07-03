
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>

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

class Solution {
public:
	string getPermutation(int n, int k) {
		string num = "123456789";
		num = num.substr(0, n);
		string res = "";
		k--;
		for (int i = n; i > 1 ; --i) {
			int f = factorial(i - 1);
			int a = k / f;
			k = k % f;
			res += num[a];
			num.erase(a, 1);
		}
		res += num;
		return res;
	}

	int factorial(int n) {
		if (n == 1) {
			return 1;
		}
		else if(n == 0)
		{
			return 0;
		}
		return n * factorial(n - 1);
	}
};

int main()
{
	Solution test = Solution();
	string res;	
	res = test.getPermutation(4,9);
	cout << res <<endl;
}