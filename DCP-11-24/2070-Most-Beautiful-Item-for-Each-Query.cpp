class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res(queries.size(), 0);
        vector<pair<int,int>> newQueries;

        for(int i=0; i<queries.size();i++) newQueries.push_back({queries[i], i});

        sort(items.begin(), items.end());
        sort(newQueries.begin(), newQueries.end());

        int i = 0;
        int curr = 0;
        for(auto [query, idx]: newQueries) {
            res[idx] = curr;
            while(i < items.size() && items[i][0] <= query) {
                res[idx] = max(res[idx], items[i][1]);
                i++;
            }

            curr = res[idx];
        }

        return res;
    }
};