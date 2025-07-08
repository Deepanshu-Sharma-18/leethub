class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,  vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n , vector<int>(m , 1e9));
        dis[0][0] = 0;
        pq.push({0,{0,0}});
    
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int i = it.second.first;
            int j = it.second.second;

            if(i == n-1 && j == m-1) return diff;


            vector<vector<int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};

            for(auto axis : d){
                int x = axis[0] + i;
                int y = axis[1] + j;

                if(x >=0 && y >= 0 && x < n && y < m ){
                    int step = abs(heights[i][j] - heights[x][y]);
                    int maxstep = max(diff, step);

                    if(maxstep < dis[x][y]){
                        pq.push({maxstep, {x , y}});
                        dis[x][y] = maxstep;
                    }

                }
            }
        }

        return 0;
    }
};