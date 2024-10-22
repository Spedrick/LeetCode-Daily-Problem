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
    void preOrder(TreeNode* root, int level, unordered_map<int, long long> &um) {
        if(!root) return;

        if(um.find(level) == um.cend()) um[level] = root->val;
        else um[level] += root->val;

        preOrder(root->right, level+1, um);
        preOrder(root->left, level+1, um);
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int, long long> um;
        preOrder(root, 0, um);

        vector<long long> res;
        for(auto x: um) {
            // cout << x.first << " " << x.second << endl;
            res.push_back(x.second);
        }
        sort(res.rbegin(), res.rend());
        return k > res.size() ? -1 : res[k-1];
    }
};