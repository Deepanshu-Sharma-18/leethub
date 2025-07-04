class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                queue<int> q;
                count++;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    auto it = q.front();
                    q.pop();

                    for(int j=0; j<n; j++){
                        if(isConnected[it][j] == 1 && !vis[j]){
                            q.push(j);
                            vis[j] =1;
                        }
                    }
                }
            }
        }

        return count;
    }
};