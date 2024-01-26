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
    void solution(TreeNode* root , TreeNode* p , vector<TreeNode*> &t){
        if(root == p){
            t.push_back(root);
            return;
        }
        if(root == NULL || (t.size() > 0 && t[t.size()-1] == p)){
            return;
        }

        t.push_back(root);
        solution(root->left , p , t);
        solution(root->right , p , t);

        if( (t.size() > 0 && t[t.size()-1] ==p )){
            return;
        }
        t.pop_back();

        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a;
        vector<TreeNode*> b;

        solution(root , p , a);
        solution(root , q , b);

        TreeNode* ans = root;
        for(int i = 0 ; i<min(a.size() , b.size()) ; i++){
            if(find(b.begin() , b.end() , a[i]) != b.end())
                ans = a[i];
        }

        return ans;
    }
};