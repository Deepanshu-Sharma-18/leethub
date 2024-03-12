class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][2] , flights[i][1]});
        }

        vector<int> dist(n,1e9);

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src] = 0;

        while(!q.empty()){
            auto s = q.front();
            q.pop();

            if(s.first > k) continue;

            for(auto it : adj[s.second.first]){
                if(s.second.second + it.first < dist[it.second] && s.first <= k){
                    dist[it.second] = s.second.second + it.first;
                    q.push({s.first + 1 , {it.second , dist[it.second]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];


    }
};