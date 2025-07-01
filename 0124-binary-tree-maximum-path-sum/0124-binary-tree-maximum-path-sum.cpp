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
    int f(TreeNode* root, int &sum){
        if(root == nullptr) return 0;

        int a = f(root->left, sum);
        int b = f(root->right, sum);

        a  = max(0 , a); 
        b = max(0 , b);

        sum = max(sum , root->val + a + b);

        return root->val + max(a , b);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        f(root, sum);
        return sum;
    }
};