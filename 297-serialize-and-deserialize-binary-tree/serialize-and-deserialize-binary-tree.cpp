/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "#";
        }
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root->val) + ",";

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left != NULL){
                q.push(temp->left);
                ans += to_string(temp->left->val) + ",";
            }else{
                ans += "#,";
            }

            if(temp->right != NULL){
                q.push(temp->right);
                ans += to_string(temp->right->val) + ",";
            }else{
                ans += "#,";
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#"){
            return NULL;
        }

        queue<TreeNode*> q;
        string str;
        stringstream ss(data);
        getline(ss , str , ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            getline( ss, str , ',');

            if(str == "#"){
                temp->left = NULL;
            }else{
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }

             getline(ss , str , ',');

            if(str == "#"){
                temp->right = NULL;
            }else{
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));