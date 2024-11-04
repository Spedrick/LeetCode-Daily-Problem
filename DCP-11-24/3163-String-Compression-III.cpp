class Solution {
public:
    string compressedString(string word) {
        string res;

        for(int i=0; i<word.size();i++) {
            int c = 1;
            char ch = word[i];
            while(i+1 < word.size() && word[i+1] == ch) {c++; i++;}

            while(c) {
                if(c >= 9) {
                    res += "9";
                    res.push_back(ch);
                    c -= 9;
                } else {
                    res += to_string(c);
                    res.push_back(ch);
                    c = 0;
                }
            }
        }

        return res;
    }
};