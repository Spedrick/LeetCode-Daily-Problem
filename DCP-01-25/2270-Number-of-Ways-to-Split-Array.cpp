class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long leftSideSum = 0, rightSideSum = 0;
        int res = 0;

        for (int num : nums) rightSideSum += num;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSideSum += nums[i];
            rightSideSum -= nums[i];

            if (leftSideSum >= rightSideSum) res++;
        }

        return res;
    }
};