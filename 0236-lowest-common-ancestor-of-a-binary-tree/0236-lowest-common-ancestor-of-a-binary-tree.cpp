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
    bool f(TreeNode* root, TreeNode* p, TreeNode* q, stack<TreeNode*>& st){
        if(root == nullptr) return false;

        if(root == p || root == q){
            st.push(root);
            return true;
        }

        st.push(root);

        bool a = f(root->left, p, q, st);
        if(a) return true;
        bool b = f(root->right, p, q,st );
        if(b) return true;

        return false;
    }
    bool ff(TreeNode* root, TreeNode* fin){
        if(root == nullptr) return false;

        if(root == fin) return true;

        bool a = ff(root->left, fin);
        if(a) return true;
        bool b = ff(root->right, fin);
        if(b) return true;

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;

        f(root, p , q, st);

        TreeNode* fin;
        if(st.top() == p){
            fin = q;
        }else{
            fin = p;
        }

        while(!st.empty()){
            TreeNode* it = st.top();
            st.pop();

            if(ff(it, fin)) return it;
        }

        return nullptr;
    }
};