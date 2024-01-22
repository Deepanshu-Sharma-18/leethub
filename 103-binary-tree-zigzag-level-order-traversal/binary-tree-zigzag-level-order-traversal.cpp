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
    map<int,vector<int>> mp;
    int maxh = 0;
    void solution(TreeNode* root , int height){
        if(root == NULL){
            if(maxh < height)
                maxh = height;
            return ;
        }

        mp[height].push_back(root->val);

        solution(root->left , height+1);
        solution(root->right , height + 1);

        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solution(root , 1);
        vector<vector<int>> ans;
        for(int i=1;i<maxh;i++){
            if(i%2 == 0)
                reverse(mp[i].begin() , mp[i].end());
            ans.push_back(mp[i]);
        }

        return ans;
    }
};