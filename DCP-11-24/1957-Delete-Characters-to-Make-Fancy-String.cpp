class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int i = 0;

        for(char c: s) {
            if(res.size() >= 2 && res[i-1] == c && res[i-2] == c) continue;
            else {res.push_back(c); i++;}
        }
        
        return res;
    }
};