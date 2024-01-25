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
    map<int,vector<pair<int,int>>> mp;
    set<int> a;
    
    void solution(TreeNode* root , int value, int colVal){
        if(root == NULL){
            return;
        }

        a.insert(value);
        mp[value].push_back({ colVal,root->val});

        solution(root->left , value -1 , colVal + 1);
        solution(root->right , value +1 , colVal + 1);

        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        solution(root , 0 , 0);
        vector<pair<int,int>> temp;
        vector<int> depair;
        for(auto i = a.begin(); i != a.end() ; i++){
            temp = mp[*i];
            sort(temp.begin(),temp.end());
            for(int j = 0;j<temp.size();j++){
                for(int k = j+1 ; k<temp.size();k++){
                    if(temp[j].first == temp[k].first){
                        if(temp[j].second > temp[k].second){
                            
                            int t = temp[j].second;
                            temp[j].second = temp[k].second;
                            temp[k].second = t;
                        }
                    }
                }
                depair.push_back(temp[j].second);
            }
            ans.push_back(depair);
            depair = {};
        }
        return ans;
    }
};