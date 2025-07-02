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
    TreeNode* tree(vector<int>& pre, vector<int>& ino, int a, int b, int c, int d){
        if(a > b || c > d) return nullptr;

        TreeNode* root = new TreeNode(pre[a]);
        int i = 0;
        for( i = c; i<=d; i++ ){
            if(ino[i] == root->val){
                break;
            }
        }

        root->left = tree(pre, ino, a + 1, a + i - c, c, i-1 );
        root->right = tree(pre, ino, a + i - c + 1, b, i+1, d);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return tree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};