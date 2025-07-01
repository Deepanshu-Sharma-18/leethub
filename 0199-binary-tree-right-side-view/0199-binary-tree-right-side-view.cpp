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

    void f(TreeNode* root, vector<int> &ans, int& maxi, int h){
        if(root == nullptr) return;

        if(h > maxi){
            ans.push_back(root->val);
            maxi = h;
        }

        f(root->right, ans, maxi, h + 1);
        f(root->left, ans, maxi, h + 1);

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxi = -1;
        f(root, ans, maxi,0);
        return ans;
    }
};