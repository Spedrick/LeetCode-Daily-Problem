class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res(queries.size(), 0);
        vector<vector<int>> newQueries;

        for(int i=0; i<queries.size();i++) newQueries.push_back({queries[i], i});

        sort(items.begin(), items.end());
        sort(newQueries.begin(), newQueries.end());

        int i = 0;
        int curr = 0;
        for(auto qq: newQueries) {
            int query = qq[0];
            int idx = qq[1];
            int ans = curr;
            while(i < items.size() && items[i][0] <= query) {
                ans = max(ans, items[i][1]);
                i++;
            }

            res[idx] = ans;
            curr = ans;
        }

        return res;
    }
};