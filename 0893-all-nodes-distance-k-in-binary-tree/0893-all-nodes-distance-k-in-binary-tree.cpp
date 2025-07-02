/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root, map<TreeNode*, TreeNode*>& mp, TreeNode* target){
        if(root == nullptr) return;
        if(root == target) return;

        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;

        f(root->left, mp, target);
        f(root->right, mp, target);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        map<TreeNode* , bool> vis;

        f(root, mp, target);

        q.push(target);
        vis[target] = true;
        int level = 0;
        vector<int> ans;

        while(!q.empty()){
            int s = q.size();

            for(int i=0; i<s; i++){
                auto it = q.front();
                q.pop();

                vis[it] = true;

                if(level == k) ans.push_back(it->val);

                if(it->left && !vis[it->left]) q.push(it->left);
                if(it->right && !vis[it->right]) q.push(it->right);
                if(mp.find(it) != mp.end() && !vis[mp[it]]){
                    q.push(mp[it]);
                }
            
            }
            if(level == k) break;
            level++;
        }


        return ans;
        
    }
};