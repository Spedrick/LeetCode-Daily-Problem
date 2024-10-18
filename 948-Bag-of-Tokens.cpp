class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x: nums) pq.push(x);

        for(int i=0;i<nums.size();i++) {
            nums[i] = pq.top();
            pq.pop();
        }

        return nums;
    }
};


//  5 2 1 3

//  5 2    1 3
// 5   2    1    3
//  2 5     1 3
//  1 2 3 5  