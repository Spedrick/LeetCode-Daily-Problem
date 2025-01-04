class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_map<char, pair<int, int>> um;
        
        for (int i = 0; i < n; i++) {
            if (um.find(s[i]) == um.end()) um[s[i]].first = i;
            um[s[i]].second = i;
        }
        
        int ans = 0;
        for (auto& [ch, positions] : um) {
            int left = positions.first;
            int right = positions.second;
            
            if (right - left <= 1) continue;
            unordered_set<char> uniqueChars;

            for (int i = left + 1; i < right; i++) {
                uniqueChars.insert(s[i]);
            }
            
            ans += uniqueChars.size();
        }
        
        return ans;
    }
};