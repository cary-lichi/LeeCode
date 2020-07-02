class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if (n == 0) {
            return "/";
        }

        stack<string> pathStack;

        for (int i = 0; i < n; ++i) {
            string temp = "";
            while (i < n && path[i] != '/') {
                temp += path[i];
                ++i;
            }

            if (temp == "..") {
                if(!pathStack.empty()){
                    pathStack.pop();
                }
            }
            else if (temp != "." && temp != "") {
                pathStack.push(temp);
            }
        }
        string res = "";
        if(pathStack.empty()){
            return "/";
        }
        while (!pathStack.empty()) {
            res = "/" + pathStack.top() + res;
            pathStack.pop();
        }
        return res;
    }
};