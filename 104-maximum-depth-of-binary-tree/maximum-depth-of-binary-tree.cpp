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
    int maxH = 0;
    void solution(TreeNode* root , int height){
        if(root == NULL){
            if(height > maxH){
                maxH = height;
            }
            return;
        }

        solution(root->left , ++height);
        --height;
        solution(root->right , ++height);
        --height;
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        solution(root->left , 1);
        solution(root->right , 1);

        return maxH;
    }
};