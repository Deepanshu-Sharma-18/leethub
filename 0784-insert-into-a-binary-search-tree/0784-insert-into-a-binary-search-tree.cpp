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
    
    void f(TreeNode* root, int& val){
        if(root->val > val){
            if(root->left) f(root->left, val);
            else root->left = new TreeNode(val);
            return;
        }else{
            if(root->right) f(root->right, val);
            else root->right = new TreeNode(val);
            return;
            f(root->right, val);
        }

        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return root = new TreeNode(val);
        }
        f(root, val);
        return root;
    }
};