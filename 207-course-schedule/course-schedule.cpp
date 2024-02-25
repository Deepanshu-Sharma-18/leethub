class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        queue<int> q;
        int cnt = 0;

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i =0;i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            auto a = q.front();
            q.pop();
            cnt++;

            for(auto it : adj[a]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }


        if(cnt == numCourses) return true;
        return false;

    }
};