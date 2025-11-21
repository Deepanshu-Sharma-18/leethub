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
    void sum(TreeNode* root, bool right, int& ans){
        if(!root) return;
        if(!root->left && !root->right){
            if(!right) ans += root->val;
            return;
        }

        sum(root->left, false, ans);
        sum(root->right, true, ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sum(root , true, ans);
        return ans;
    }
};