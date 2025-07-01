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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);

        int odd = 0;

        while(!q.empty()){
            int s = q.size();
            vector<int> temp;

            for(int i=0; i<s; i++){
                auto *it = q.front();
                q.pop();

                temp.push_back(it->val);

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }

            if(odd % 2 == 1){
                reverse(temp.begin(), temp.end());
            }
            odd++;
            ans.push_back(temp);
        }

        return ans;

    }
};