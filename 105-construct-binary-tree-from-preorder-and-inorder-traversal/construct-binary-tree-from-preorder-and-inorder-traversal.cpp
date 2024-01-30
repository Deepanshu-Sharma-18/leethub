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

    TreeNode* constructTree(
        vector<int>& preorder,
        vector<int>& inorder ,
        int preStart ,
        int preEnd ,
        int inStart ,
        int inEnd ,
        map<int,int> &mp){

            if(preStart > preEnd || inStart > inEnd) return NULL;

            TreeNode* root = new TreeNode(preorder[preStart]);
            int ind = mp[preorder[preStart]];
            int nextIndex = ind - inStart;

            root->left = 
                constructTree(preorder , inorder , preStart + 1 , preStart + nextIndex , inStart , ind -1 , mp);
            root->right = 
                constructTree(preorder , inorder , preStart + 1 + nextIndex , preEnd , ind + 1, inEnd , mp);

            return root;    

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return constructTree(preorder , inorder , 0 , preorder.size()-1 , 0 , inorder.size() -1 , mp);
    }
};