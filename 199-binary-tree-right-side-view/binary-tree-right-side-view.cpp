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
    vector<int> ans;
    int minheight = 1;
    void solution(TreeNode* root , int height){
        if(root == NULL){
            return;
        }

        if(height  == minheight ){
            ans.push_back(root->val);
            minheight++;
        }

        solution(root->right , height + 1);
        solution(root->left , height + 1);

        return;
    }
    vector<int> rightSideView(TreeNode* root) {
      
        solution(root , 1);
        return ans;
    }
};