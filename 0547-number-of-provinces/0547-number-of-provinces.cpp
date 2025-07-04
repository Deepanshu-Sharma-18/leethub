class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count = 0;

        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                queue<int> q;
                count++;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();

                    for(auto node : adj[it]){
                        if(!vis[node]){
                            q.push(node);
                            vis[node] = 1;
                        }
                    }
                }
            }
        }

        return count;
    }
};