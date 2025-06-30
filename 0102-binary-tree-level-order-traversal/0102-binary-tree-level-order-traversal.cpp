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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;

        vector<vector<int>> ans;

        q.push(root);
        
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> t;

            for(int i=0; i<levelSize; i++){
                auto *it = q.front();
                q.pop();

                t.push_back(it->val);

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans.push_back(t);
        }

        return ans;
    }
};