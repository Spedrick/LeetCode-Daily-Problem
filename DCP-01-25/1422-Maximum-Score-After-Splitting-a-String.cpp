class Solution {
public:
    int maxScore(string s) {
        int leftScore = 0, rightScore = 0, res = 0;

        for(int i=0; i< s.size(); i++) {
            if(i < 1 && s[i] == '0') leftScore++;
            if(i > 0 && s[i] == '1') rightScore++;
        }

        res = leftScore + rightScore;
        for(int i=1; i<s.size()-1;i++) {
            if(s[i] == '1') rightScore--;
            if(s[i] == '0') leftScore++;

            res = max(res, leftScore + rightScore);
            // cout << leftScore << " " << rightScore << endl;
        }

        return res;
    }
};