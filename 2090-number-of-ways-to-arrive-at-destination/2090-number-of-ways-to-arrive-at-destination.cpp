class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n, LLONG_MAX);
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        vector<int> ways(n, 0);
        ways[0] = 1;
        
        pq.push({0,0});
        dist[0] = 0;

        int mod = 1e9 + 7;

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();

            if(time > dist[node]) continue;

            for(auto [nde, tme] : adj[node]){
                if(dist[nde] > time + tme){
                    dist[nde] = time + tme;
                    ways[nde] = ways[node];
                    pq.push({dist[nde] , nde});
                }else if(dist[nde]  ==  tme + time){
                    ways[nde] = (ways[node] + ways[nde]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};