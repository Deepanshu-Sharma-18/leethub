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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long ans = 0;

        while(!q.empty()){
            int s = q.size();
            unsigned long long mini = 0 ;
            unsigned long long maxi  = 0;
            int ind = q.front().second;
            for(int i=0; i<s; i++){
                auto it = q.front();
                q.pop();
                unsigned long long index = it.second - ind;

                if(i == 0) mini = index;
                if(i == s-1) maxi = index;

                if(it.first->left){
                    q.push({it.first->left, (index * 2)});
                }
                if(it.first->right) {
                    q.push({it.first->right, (index * 2) + 1});
                }
            }
            ans = max(ans , maxi - mini + 1);
        }

        return ans;
    }
};