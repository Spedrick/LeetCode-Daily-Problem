class Solution {
    void solve(vector<int>& nums, int i, int curr, int &res, int &max) {
        if(i >= nums.size()) return;
        if((curr | nums[i]) == max) res++;

        solve(nums, i+1, curr | nums[i], res, max);
        solve(nums, i+1, curr, res, max);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int res = 0;
        int max = 0;
        for(int x: nums) max = max | x;
        solve(nums, 0, 0, res, max);
        return res;        
    }
};