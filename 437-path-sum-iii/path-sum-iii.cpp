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

    void f(TreeNode* root , long target , int& count){
        if(root == NULL){
            return;
        }

        if(target == root->val){
            count++;
        }    

        f(root->left , target - root->val , count);
        f(root->right , target - root->val , count);

        return;
    }
    void s(TreeNode* root , int target, int & count){
        if(root == NULL){
            return;
        }

        f(root,target,count);

        s(root->left , target , count);
        s(root->right , target , count);

        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        s(root,targetSum ,count);
        return count;
    }
};