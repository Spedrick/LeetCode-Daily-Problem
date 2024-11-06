class Solution {
    int tobinc(int x) {
        int c = 0;
        while(x) {
            if(x%2) c++;
            x = x/2;
        }
        return c;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int setBits = tobinc(nums[0]);
        int prevMax = INT_MIN;

        int currMax = nums[0];
        int currMin = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            if (setBits == tobinc(nums[i])) {
                currMax = max(currMax, nums[i]);
                currMin = min(currMin, nums[i]);
            } else {
                if (currMin < prevMax) return false;

                prevMax = currMax;
                setBits = tobinc(nums[i]);

                currMin = nums[i];
                currMax = nums[i];
            }
        }

        return currMin > prevMax;
    }
};