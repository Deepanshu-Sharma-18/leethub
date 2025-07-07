class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }

        queue<int> q;
        for(int i=0; i<ind.size(); i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            ans.push_back(it);

            for(auto node : adj[it]){
                ind[node]--;
                if(ind[node] == 0) q.push(node);
            }
        }

        if(ans.size() == numCourses) return ans;
        return {};
    }
};