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
    void f(TreeNode* root, map<int, vector<pair<int,int>>> &mp, int col, int row, int& mini, int& maxi){
        if(root == nullptr) return;

        mini = min(mini, col);
        maxi = max(maxi, col);
        
        mp[col].push_back({row, root->val});
        
        f(root->left, mp, col-1, row + 1,  mini, maxi);
        f(root->right, mp, col+1, row + 1, mini, maxi);


    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> mp;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        f(root, mp,0, 0,mini,maxi);
        for(int i = mini; i<=maxi; i++){
            auto it = mp[i];
            sort(it.begin(), it.end());
            vector<int> t;
            for(int j=0; j<it.size(); j++){
                t.push_back(it[j].second);
            }
            ans.push_back(t);
        }

        return ans;
    }
};