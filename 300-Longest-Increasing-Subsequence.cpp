class Solution {
    vector<int> um;
    int f(vector<int>& nums, int idx) {
        if(idx == nums.size()-1) return 1;
        if(um[idx] != -1) return um[idx];

        int res = 0;
        for(int i=idx+1; i<nums.size(); i++) {
            if(nums[i] > nums[idx]) {
                res = max(res, f(nums, i));
            }
        }

        um[idx] = 1 + res;
        return 1 + res;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        um = vector(2501, -1);

        for(int i=0;i<nums.size();i++) {
            // int temp = ;
            res = max(res,f(nums,i));
            // cout << i << \ \ << temp << \ \ << res << endl;;
        }
        return res;
    }
};