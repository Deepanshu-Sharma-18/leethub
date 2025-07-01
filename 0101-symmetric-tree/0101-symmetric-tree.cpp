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
    bool f(TreeNode* l , TreeNode* r){
        if(l == nullptr && r == nullptr) return true;

        if(l == nullptr || r == nullptr) return false;

        if(l->val != r->val) return false;

        bool a = f(l->left , r->right); 
        bool b = f(l->right , r->left); 

        if(a == false || b == false) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return f(root->left, root->right);
    }
};