class Solution {
    int f(int start, int end, int n, const vector<vector<int>>& graph) {
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int u : graph[curr]) {
                if (dist[u] > dist[curr] + 1) {
                    dist[u] = dist[curr] + 1;
                    q.push(u);
                }
            }
        }

        return dist[end];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> graph(n);

        for (int i = 0; i < n - 1; i++) graph[i].push_back(i + 1);

        for (auto query : queries) {
            int u = query[0], v = query[1];
            graph[u].push_back(v);
            answer.push_back(f(0, n - 1, n, graph));
        }

        return answer;
    }
};