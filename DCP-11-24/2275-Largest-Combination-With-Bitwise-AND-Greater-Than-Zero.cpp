class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> arr(32, 0);
        int res = 0;

        for(int x: candidates) {
            int i=0;
            while(x > 0) { 
                arr[i] += x&1;
                res = max(res, arr[i]);
                i++;
                x = x >> 1;
            }
        }

        return res;
    }
};