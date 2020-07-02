class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int n = s.size();
        for(int i = 0; i < n; ++i){
            string temp = "";
            while(i < n && s[i] != ' '){
                temp += s[i];
                ++i;
            }
            if(temp != ""){
                if(res == ""){
                    res = temp;
                }else{
                    res = temp +" "+ res;    
                }
            }
        }
        return res;
    }
};