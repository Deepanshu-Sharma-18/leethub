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
    vector<int> findLeaf(TreeNode *root , vector<int> &a){
        if(root == NULL){
            return a;
        }
        if(root->left == NULL && root->right == NULL){
            a.push_back(root->val);
            return a;
        }

        findLeaf(root->left , a);
        findLeaf(root->right, a);
        return a;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        findLeaf(root1, a);
        findLeaf(root2 , b);

        return a == b;
    }
};