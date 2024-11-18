class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res;
        int curr = 0, n = code.size();

        int i = k>=0 ? 0 : n+k-1;
        int j = i;

        if(k < 0) k *= -1;

        while(k--) {
            curr += code[j%n];
            j++;
        }

        while(res.size() < n) {
            curr -= code[i%n];
            curr += code[j%n];

            res.push_back(curr);
            i++; j++;
        }
        return res;        
    }
};