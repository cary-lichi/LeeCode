
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>

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
    vector<string> res;
    vector<string> ips;

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n < 4 || n > 12) {
            return {};
        }
        dfs(s, 0, 4);
        return res;
    }

    void dfs(string s, int prvpos, int deep) {
        int n = s.size();
        if (deep == 1 ){
            string ip = s.substr(prvpos);
            if (isNum(ip)) {
                string address = "";
                int n = ips.size();
                for (int i = 0; i < n; ++i) {
                    address += ips[i];
                    address += ".";
                }
                address += ip;
                res.push_back(address); 
            }
            return;
        }
      
        for (int i = 1; i <= 3; ++i) {
            if (prvpos + i > n) {
                break;
            }
            string ip = s.substr(prvpos, i);
            if (isNum(ip)) {
                ips.push_back(ip);
                dfs(s, prvpos + i, deep - 1);
                ips.pop_back();
            }
        }
    }

    bool isNum(string s) {
        if (s == "") {
            return false;
        }

        if (s.size() > 1 && s[0] == '0') {
            return false;
        }

        int num = stoi(s);

        return num >= 0 && num <= 255;
    }
};


int main()
{
	Solution test = Solution();
	//string res;
    //int res;
    vector<string> res;

    res = test.restoreIpAddresses("0101010");
    coutVertor(res);
}
