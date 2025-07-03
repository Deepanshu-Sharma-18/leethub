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
    TreeNode* f(vector<int>& preorder, int i, int j){
        if(i > j) return nullptr;

        TreeNode* root = new TreeNode(preorder[i]);
        
        int ind = i;
        while(ind <= j && preorder[ind] <= preorder[i]) ind++;

        int cnt = ind - i - 1;

        root->left = f(preorder, i + 1 , i + cnt);

        root->right = f(preorder, ind , j);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return f(preorder, 0, preorder.size()-1);
    }
};