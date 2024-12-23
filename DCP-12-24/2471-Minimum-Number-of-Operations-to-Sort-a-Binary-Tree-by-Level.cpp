/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int f(vector<int>& arr) {
        int n = arr.size();
        pair<int, int> arrPos[n];
        
        for (int i = 0; i < n; i++) {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }

        sort(arrPos, arrPos + n);

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || arrPos[i].second == i)continue;

            int cycle_size = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = 1;
                j = arrPos[j].second;

                cycle_size++;
            }

            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }

        return ans;
    }   

public:
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;

        unordered_map<int, vector<int>> um;
        queue<pair<TreeNode*, int>> qq;

        qq.push({root, 1});
        while(!qq.empty()) {
            TreeNode* curr = qq.front().first;
            int level = qq.front().second;
            qq.pop();

            um[level].push_back(curr->val);

            if(curr->left) qq.push({curr->left, level + 1});
            if(curr->right) qq.push({curr->right, level + 1});
        }

        int res = 0;
        for(auto vals: um) {
            // for(int x: nums.second) cout << x << " ";
            // cout << endl;
            res += f(vals.second);
        }

        return res;        
    }
};