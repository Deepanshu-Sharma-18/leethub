class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        q.push({0, k});
        dist[k] = 0;

        while(!q.empty()){
            auto [currdist, node] = q.top();
            q.pop();

            for(auto [nde, dst] : adj[node]){
                if(dist[nde] > currdist + dst){
                    dist[nde] = currdist + dst;
                    q.push({dist[nde], nde});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1; 
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;

    }
};