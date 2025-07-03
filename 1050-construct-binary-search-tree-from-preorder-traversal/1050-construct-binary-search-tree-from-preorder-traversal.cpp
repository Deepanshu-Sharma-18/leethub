class Solution {
public:
    int i = 0;

    TreeNode* f(vector<int>& preorder, int bound) {
        if (i == preorder.size() || preorder[i] > bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = f(preorder, root->val);
        root->right = f(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return f(preorder, INT_MAX);
    }
};
