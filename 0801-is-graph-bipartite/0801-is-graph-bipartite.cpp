class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<bool>& vis, vector<int>& bi, int node){
        queue<int> q;

        q.push(node);
        vis[node] = true;
        bi[node] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            for(auto node : graph[it]){
                if(!vis[node]){
                    vis[node] = true;
                    if(bi[it] == 1){
                        q.push(node);
                        bi[node] = 0;
                    }else{
                        q.push(node);
                        bi[node] = 1;
                    }
                }else{
                    if(bi[it]  == bi[node]) return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<int> bi(n, -1);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(!bfs(graph,vis,bi,i)) return false;
            }
        }

        return true;
        
    }
};