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
     bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
    
    bool solve(TreeNode* root, TreeNode* max, TreeNode* min){
        if(root==NULL){
            return true;
        }
		
        if((min==NULL || root->val > min->val) && (max==NULL || root->val < max->val)){
            return solve(root->left, root, min) && solve(root->right, max, root);
        }
        return false;
    }
};