class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});

        int n = image.size();
        int m = image[0].size();
        int c = image[sr][sc];

        image[sr][sc] = -1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            if(it.first - 1 >=0 && image[it.first - 1][it.second] == c){
                image[it.first - 1][it.second] = -1;
                q.push({it.first - 1, it.second});
            }
            if(it.first + 1 < n && image[it.first + 1][it.second] == c){
                image[it.first + 1][it.second] = -1;
                q.push({it.first + 1, it.second});
            }
            if(it.second - 1 >=0 && image[it.first][it.second - 1] == c){
                image[it.first][it.second - 1] = -1;
                q.push({it.first, it.second - 1});
            }
            if(it.second + 1 < m && image[it.first][it.second + 1] == c){
                image[it.first][it.second + 1] = -1;
                q.push({it.first, it.second + 1});
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(image[i][j] == -1) image[i][j] = color;
            }
        }

        return image;
    }
};