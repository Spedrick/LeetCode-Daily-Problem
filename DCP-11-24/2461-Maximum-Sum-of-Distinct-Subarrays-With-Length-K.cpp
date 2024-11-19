class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> um;
        long long res = 0;

        int i=0;
        long long curr = 0;
        
        for(int j=0; j<nums.size(); j++) {
            if(um.find(nums[j]) == um.cend()) {
                curr += nums[j];
                um.insert(nums[j]);

                if(j - i + 1 == k) {
                    res = max(res, curr);
                    
                    curr -= nums[i];
                    um.erase(nums[i]);
                    i++;
                }
            } else {
                while(nums[i] != nums[j]) {
                    curr -= nums[i];
                    um.erase(nums[i]);
                    i++;
                }
                i++;
            }
        }


        return res;        
    }
};