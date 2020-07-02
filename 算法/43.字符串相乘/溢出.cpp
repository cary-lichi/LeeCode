
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0) {
            return 0;
        }
        int n1 = stringToInt(num1);
        int n2 = stringToInt(num2);

        int res = n1 * n2;

        return intToString(res);
    }

    int stringToInt(string str) {
        int num = 0;
        for (int i = 0; i < str.size(); ++i) {
            num += (str[i] - '0') * pow(10, str.size() - 1 - i);
        }
        return num;
    }

    string intToString(int num) {
        string res = "";
        if (num == 0) {
            return "0";
        }
        while (num > 0) {
            char n = ('0' + num % 10);
            res = n + res;
            num /= 10;
        }
        return res;
    }
};

int main()
{
	Solution test = Solution();
	string res;


    res = test.multiply("123456789", "987654321");
    cout << res << endl;

    res = test.multiply("0", "0");
    cout << res << endl;

	res = test.multiply("20", "20");
	cout << res << endl;


}
