class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;

        for(int i=0;i<=nums.size()-k;i++) {
            int max_ele = nums[i];
            bool isCons = true;
            for(int j=i+1; j<i+k; j++) {
                if(nums[j] != nums[j-1] + 1) isCons = false;
                max_ele = max(max_ele, nums[j]);
            }

            if(isCons) res.push_back(max_ele);
            else res.push_back(-1);
        }
        
        return res;
    }
};