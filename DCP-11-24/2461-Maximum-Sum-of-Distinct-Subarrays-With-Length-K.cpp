class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<bool> um(100001, false);
        long long res = 0, curr = 0;
        
        for(int j=0,i=0; j<nums.size(); j++) {
            if(um[nums[j]] == 0) {
                curr += nums[j];
                um[nums[j]] = 1;

                if(j - i + 1 == k) {
                    res = max(res, curr);

                    curr -= nums[i];
                    um[nums[i]] = 0;
                    i++;
                }
            } else {
                while(nums[i] != nums[j]) {
                    curr -= nums[i];
                    um[nums[i]] = 0;
                    i++;
                }
                i++;
            }
        }


        return res;        
    }
};