class Solution {
public:

    void dfs(vector<vector<int>> &adj , int node, vector<int>& vis){
        vis[node] = 1;
        for(int i=0;i<adj.size();i++){
            if(vis[i] == 0 && adj[node][i] == 1){
                dfs(adj , i , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int size = isConnected.size();

        vector<int> vis(size,0);

        for(int i=0;i<size;i++){
            if(vis[i] == 0){
                count++;
                dfs(isConnected , i , vis);
            }
        }
        return count;
    }
};