class Solution {
public:

    bool dfs( vector<vector<int>>& graph , int num , vector<int> &color , int node){
        color[node] = num;

        for(auto it : graph[node]){
            if(color[it] == -1){
                if(!dfs(graph, !num , color , it)) return false;
            }
            else if(color[it] == color[node]) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size() , -1);

        for(int i=0;i<graph.size();i++){
            if(color[i] == -1){
                if(!dfs(graph, 0 ,color,i)) return false;
            }
        }

        return true;
    }
};