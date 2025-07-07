class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }

        queue<int> q;
        for(int i=0; i<ind.size(); i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            count++;

            for(auto node : adj[it]){
                ind[node]--;
                if(ind[node] == 0) q.push(node);
            }
        }

        if(count == numCourses) return true;
        return false;
        

    }
};