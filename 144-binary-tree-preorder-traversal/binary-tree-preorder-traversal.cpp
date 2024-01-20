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
    vector<int> preorderTraversal(TreeNode* root) {
        // if(root == NULL){
        //     return ans;
        // }
        // ans.push_back(root->val);
        // preorderTraversal(root->left);
        // preorderTraversal(root->right);


        vector<int> ans;
        stack<pair<TreeNode* , bool>> nodes;
        TreeNode* temp = root;
        pair<TreeNode* , bool> p;

        while(temp != NULL){
            ans.push_back(temp->val);
            nodes.push({temp , false});
            temp = temp->left;
        }


        while(nodes.size() != 0){
            p = nodes.top();
            temp = nodes.top().first;
            if(temp->right != NULL && p.second == false ){
                p.second = true;
                nodes.pop();
                nodes.push(p);
                p = nodes.top();
                temp = temp->right;
                while(temp != NULL){
                    ans.push_back(temp->val);
                    nodes.push({temp , false});
                    temp = temp->left;
                }
            }else{
                if(find(ans.begin() , ans.end() , temp->val) != ans.end() ){
                    nodes.pop();
                }else{
                    ans.push_back(temp->val);
                    nodes.pop();
                }
            }

        }

        return ans;
    }
};