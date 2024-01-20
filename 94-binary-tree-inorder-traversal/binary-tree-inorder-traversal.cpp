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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        
        stack<TreeNode*> nodes;

        TreeNode* temp = root;
        while(temp != NULL){
            nodes.push(temp );
            temp = temp->left;
        }

        while(nodes.size() != 0){
            temp =  nodes.top();
            ans.push_back(temp->val);
            nodes.pop();

            if(temp->right != NULL){
                temp = temp->right;
                while(temp != NULL){
                    nodes.push(temp);
                    temp = temp->left;
                }
            }
        }

        return ans;

    }
};