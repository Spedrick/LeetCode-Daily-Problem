class Solution {
    bool isValid(int &i, int &j, int &n, int &m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>distance(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, 
                                vector<pair<int, pair<int, int>>>, 
                                        greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({0, {0, 0}});

        vector<pair<int, int>>directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        distance[0][0] = 0;

        while(!minHeap.empty())
        {
            auto [minDistance, idx] = minHeap.top(); minHeap.pop();
            auto [i, j] = idx;

            for(auto [ii, jj] : directions)
            {
                int ci = i + ii, cj = j + jj;
                if(isValid(ci, cj, n, m))
                {
                    int newDistance = minDistance + grid[ci][cj];
                    if(newDistance < distance[ci][cj])
                    {
                        distance[ci][cj] = newDistance;
                        minHeap.push({newDistance, {ci, cj}});
                    }
                }
            }
        }
        return distance[n - 1][m - 1];
    }
};