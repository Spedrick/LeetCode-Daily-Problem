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
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        int max_level = 0;

        unordered_map<int, priority_queue<long>> um;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 1});
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            q.pop();

            cout << curr->val << \ \ << level << endl;

            um[level].push(curr->val);
            max_level = max(max_level, level);

            if(curr->left) q.push({curr->left, level + 1});
            if(curr->right) q.push({curr->right, level + 1});
        }

        cout << endl << max_level;

        vector<int> res(max_level, 0);
        for(auto ele: um) {
            int level = ele.first;
            res[level-1] = ele.second.top();
        }

        return res;        
    }
};