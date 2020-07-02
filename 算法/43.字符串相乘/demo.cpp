
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        if (n1 == 0 || n2 == 0) {
            return "0";
        }

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> list = vector<int>(n1 + n2);

        for (int i = n1 - 1; i >= 0; --i) {
            int m1 = num1[i] - '0';
            for (int j = n2 - 1; j >= 0; --j) {
                int m2 = num2[j] - '0';
                int temp = list[i + j + 1] + m1 * m2;
                list[i + j + 1] = temp % 10;
                list[i + j] += temp / 10;
            }
        }

        string res = "";
        for (int i = 0; i < list.size(); ++i) {
            if (i == 0 && list[0] == 0) {
                continue;
            }
            res += '0' + list[i];
        }
        return res;
    }

};

int main()
{
	Solution test = Solution();
	string res;

    res = test.multiply("9133", "0");
    cout << res << endl;

    res = test.multiply("123456789", "987654321");
    cout << res << endl;

    res = test.multiply("0", "0");
    cout << res << endl;

	res = test.multiply("20", "20");
	cout << res << endl;


}
