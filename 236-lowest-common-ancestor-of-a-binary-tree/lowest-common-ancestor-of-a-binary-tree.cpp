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
    void solution(TreeNode* root , TreeNode* p , TreeNode* q , stack<TreeNode*> &t){
        if(root == NULL || ( !t.empty() && (t.top() == p || t.top() == q) )){
            return;
        }
        if(root == p || root == q){
            t.push(root);
            return;
        }

        t.push(root);
        solution(root->left , p , q , t);
        solution(root->right , p,q , t);
        if(!t.empty() && (t.top() == p || t.top() == q)){
            return;
        }
        t.pop();

        return;
    }
    bool checkforother(TreeNode* root , TreeNode * t){
        if(root == t){
            return true;
        }
        if(root == NULL){
            return false;
        }

        bool a = checkforother(root->left, t);
        if(a){
            return true;
        }

        bool b = checkforother(root->right, t);
        if(b){
            return true;
        }

        return false;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;

        solution(root , p , q , st);

        TreeNode* ans = root;
        TreeNode* other;

        if(st.top() == p){
            other = q;
        }
        else{
            other = p;
        }

        while(!st.empty()){
            ans = st.top();
            st.pop();

            if(checkforother(ans , other )){
                return ans;
            }
        }

        return ans;
    }
};