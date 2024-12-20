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
    void preOrder(TreeNode* root1, TreeNode* root2, int level) {
        if(!root1 || !root2) return;

        if(level % 2 == 1) {
            int temp = root1->val;
            root1->val = root2->val;
            root2->val = temp;
        }


        preOrder(root1->left, root2->right, level + 1);
        preOrder(root1->right, root2->left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        preOrder(root->left, root->right, 1);
        return root;
    }
};