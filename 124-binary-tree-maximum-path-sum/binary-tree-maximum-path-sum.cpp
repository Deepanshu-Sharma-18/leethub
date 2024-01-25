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
    int ans = -10000;
    int solution(TreeNode* root ){
        if(root == NULL){
            return 0;
        }

        int maxLeft = max(0,solution(root->left ));
        int maxRight = max(0,solution(root->right ));

        ans = max(ans , root->val + maxLeft + maxRight);

        return root->val + max(maxLeft , maxRight);
        
    }
    int maxPathSum(TreeNode* root) {
         solution(root );

         return ans;
    }
};