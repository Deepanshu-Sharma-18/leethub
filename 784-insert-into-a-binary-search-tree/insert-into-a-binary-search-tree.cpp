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
    TreeNode* insertIntoBST(TreeNode* temp, int val) {
        if(!temp) return new TreeNode(val);
        TreeNode* pre;
        TreeNode* root = temp;
        while(root != NULL){
            if(root->val > val){
                pre = root;
                root = root->left;
            }else{
                pre = root;
                root = root->right;
            }
        }

        if(pre->val > val){
            pre->left = new TreeNode(val);
            return temp;
        }

        pre->right = new TreeNode(val);
        return temp;
    }
};