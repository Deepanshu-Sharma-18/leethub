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
    int solution(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lh = solution(root->left);
    
        int rh = solution(root->right);

        if(lh == -1 || rh == -1)
            return -1;

        if(abs(lh - rh) > 1)
            return -1;

        
        return max(lh , rh) + 1;
        
    }

    bool isBalanced(TreeNode* root) {
        if(
            (root == NULL) || 
            (root->left == NULL && root->right == NULL)
        ){
            return true;
        }    
        return solution(root) != -1; 
    }
};