class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==1) return nums;
        vector<int> ans(n-k+1, -1);
        int len=1;

        for (int i=1; i<k; i++) {
            if (nums[i]==nums[i-1]+1) len++;
            else len = 1;
        }

        if (len==k) ans[0]=nums[k-1];

        for (int l=1, i=k; i<n; l++, i++) {
            if (nums[i]==nums[i-1]+1) len++;
            else len=1;

            if (len>=k) ans[l]=nums[i];
        }

        return ans;
    }
};