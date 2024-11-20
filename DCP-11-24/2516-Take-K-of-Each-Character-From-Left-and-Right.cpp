class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);
        int res = INT_MAX, n = s.size();

        for(char c: s) count[c - 'a']++;
        if (*min_element(count.begin(), count.end()) < k) return -1;

        int l=0;
        for(int r=0; r < n; r++) {
            count[s[r] - 'a']--;

            while (*min_element(count.begin(), count.end()) < k) {
                count[s[l] - 'a']++;
                l++;
            }

            res = min(res, n - (r-l+1));
        }
        return res;
    }
};