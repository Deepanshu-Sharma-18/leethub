class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<int> ans;
        vector<int> adj[numCourses];
        queue<int> q;
        vector<int> indegree(numCourses,0);

        for(int i =0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i =0;i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        for(int i =0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            auto a = q.front();
            q.pop();
            ans.push_back(a);

            for(auto it : adj[a]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(ans.size() != numCourses) return {};
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};