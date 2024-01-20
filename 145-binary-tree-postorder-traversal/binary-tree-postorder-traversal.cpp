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
    vector<int> postorderTraversal(TreeNode* root) {
        pair<TreeNode*,bool> p;
        stack<pair<TreeNode*,bool>> nodes;

        vector<int> ans;

        TreeNode* temp = root;

        while(temp != NULL){
            nodes.push({temp , false});
            temp = temp->left;
        }

        while(nodes.size() != 0){
            p = nodes.top();
            temp = p.first;

            if(temp->right != NULL && p.second == false){
                p.second = true;
                nodes.pop();
                nodes.push(p);

                temp = temp->right;

                while(temp != NULL){
                    nodes.push({temp,false});
                    temp = temp->left;
                }
            }else{
                ans.push_back(temp->val);
                nodes.pop();
            }
        }


        return ans;
    }
};