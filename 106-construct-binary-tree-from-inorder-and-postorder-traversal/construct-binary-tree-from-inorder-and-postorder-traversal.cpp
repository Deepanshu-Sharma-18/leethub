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
        vector<int>& postorder,
        vector<int>& inorder ,
        int postStart ,
        int postEnd ,
        int inStart ,
        int inEnd ,
        map<int,int> &mp){

            if(postStart > postEnd || inStart > inEnd) return NULL;

            TreeNode* root = new TreeNode(postorder[postEnd]);
            int ind = mp[postorder[postEnd]];
            int nextIndex = ind - inStart;

            root->left = 
                constructTree(postorder , inorder , postStart  , postStart - 1 + nextIndex , inStart , ind -1 , mp);
            root->right = 
                constructTree(postorder , inorder , postStart + nextIndex , postEnd-1 , ind + 1, inEnd , mp);

            return root;    

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return constructTree(postorder , inorder , 0 , postorder.size()-1 , 0 , inorder.size() -1 , mp);
    }
};