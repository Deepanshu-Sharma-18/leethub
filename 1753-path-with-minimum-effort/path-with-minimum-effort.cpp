class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<vector<int>,
                       vector<vector<int>>,
                       greater<vector<int>>> pq;

        vector<pair<int,int>> adj = {{-1,0} , {0,1} , {0,-1} , {1,0}};

        vector<vector<int>> dist(n , vector<int>(m,1e9));
        dist[0][0] = 0;

        pq.push({0 , 0 ,0});

        while(!pq.empty()){
            auto s = pq.top();
            pq.pop();

            if(s[1] == n-1 && s[2] == m-1){
                return s[0];
            }           

            for(auto it : adj){
                int row = it.first + s[1];
                int col = it.second + s[2];

                if(row >= 0 && row < n && col >= 0 && col < m){  
                    
                    if(max(abs(heights[s[1]][s[2]] - heights[row][col]),s[0]) < dist[row][col]){
                        dist[row][col] = max(abs(heights[s[1]][s[2]] - heights[row][col]),s[0]);
                        pq.push({dist[row][col] , row , col});
                    }
                }

            }
            
        }

        return 0;
    }

};