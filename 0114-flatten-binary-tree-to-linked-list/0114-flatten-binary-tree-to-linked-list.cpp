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
    void f(TreeNode* root){
        if(root == nullptr) return;

        if(root->left){
            TreeNode* nxt = root;;
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            while(root->right){
                root = root->right;
            }
            root->right = temp;
            root = nxt;
        }

        f(root->right);
    }
    void flatten(TreeNode* root) {
        return f(root);
    }
};