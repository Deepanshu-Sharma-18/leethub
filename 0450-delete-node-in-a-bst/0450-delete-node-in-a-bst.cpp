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
    TreeNode* f(TreeNode* root, int key){
        if(root == nullptr) return nullptr;
        if(root->val > key) root->left = f(root->left, key);

        else if(root->val < key){
           root->right = f(root->right, key);
        }else{
            if(!root->left){
                return root->right;
            }
            if(!root->right){
                return root->left;
            }

            TreeNode* t = root->right;
            while(t->left){
                t = t->left;
            }

            root->val = t->val;
            root->right = f(root->right, t->val);
        }

        return root;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return f(root, key);
    }
};