class Solution {
    void f(vector<int>& nums, int &target, int idx, long curr, int &res) {
        if(idx == nums.size() - 1) {
            if(curr + nums[idx] == target) res++;
            if(curr - nums[idx] == target) res++;
            return;
        }

        f(nums, target, idx+1, curr + nums[idx], res);
        f(nums, target, idx+1, curr - nums[idx], res);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        f(nums, target, 0, 0, res);
        return res;        
    }
};