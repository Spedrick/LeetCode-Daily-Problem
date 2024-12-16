class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<nums.size();i++) pq.push({nums[i], i});

        while(k--) {
            int x = pq.top().first;
            int idx = pq.top().second;

            pq.pop();
            pq.push({x*multiplier, idx});
        }

        while(!pq.empty()) {
            nums[pq.top().second] = pq.top().first;
            pq.pop();
        }

        return nums;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();