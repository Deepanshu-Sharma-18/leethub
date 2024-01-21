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
    pair<int,int> max = {0,0};
    pair<int,int> calLength(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pair<int,int> lh = calLength(root->left);
        pair<int,int> rh = calLength(root->right);

        

        int a ;
        if(lh.first > lh.second)
            a = lh.first;
        else
            a = lh.second; 

        int b ;
        if(rh.first > rh.second)
            b = rh.first;
        else
            b = rh.second; 

        if(max.first + max.second < a + b){
            max.first = a;
            max.second = b;
        }        

        return { (a + 1) , (b + 1) };
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        calLength(root);

        return max.first + max.second;
    }
};