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
    void solution(TreeNode* root, int& ans, int depth){
        if(!root) return;
        if(!root->left && !root->right){
            ans = min(ans, depth);
            return;
        }
        solution(root->left, ans, depth + 1);
        solution(root->right, ans, depth + 1);

        return;
    }
    int minDepth(TreeNode* root) {
        int ans = INT_MAX;
        solution(root, ans, 0);
        return ans == INT_MAX ? 0 : ans + 1; 
    }
};