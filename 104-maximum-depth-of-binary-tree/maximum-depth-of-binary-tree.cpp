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

        int lh = solution(root->left );
        int rh = solution(root->right );
        
        return max(lh , rh) + 1;
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        return solution(root);
    }
};