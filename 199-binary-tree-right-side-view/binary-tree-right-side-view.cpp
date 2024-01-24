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
    
    void solution(TreeNode* root , int height , vector<int> &ans){
        if(root == NULL){
            return;
        }

        if(height  == ans.size() ){
            ans.push_back(root->val);
        }

        solution(root->right , height + 1 , ans);
        solution(root->left , height + 1 ,ans);

        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solution(root , 0, ans);
        return ans;
    }
};