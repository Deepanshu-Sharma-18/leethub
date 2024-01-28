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
   
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        TreeNode* temp = root;
        while(temp->left != NULL || temp->right != NULL){
            if(temp->left != NULL && temp->right != NULL){
                TreeNode *t = temp->right;
                TreeNode *k = temp->left;
                while(k->right!=NULL){
                    k = k->right;
                }
                temp->right = temp->left;
                temp->left = NULL;
                k->right = t;
            }else if(temp->left != NULL && temp->right == NULL){
                temp->right = temp->left;
                temp->left = NULL;
            }
            temp = temp->right;
        }
    }
};