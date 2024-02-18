class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        queue<pair<int, int>> q;

        q.push({sr, sc});

        int num = image[sr][sc];

        image[sr][sc] = -1;

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto a = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int row = a.first + dir[i].first;
                    int col = a.second + dir[i].second;

                    if (row < image.size() && row >= 0 && col >= 0 && col <= image[0].size() && image[row][col] == num) {
                        image[row][col] = -1;
                        q.push({row, col});
                    }
                }
            }
        }


        for(int i =0; i< image.size() ; i++){
            for(int j=0 ;j < image[0].size() ; j++){
                if(image[i][j] == -1){
                    image[i][j] = color;
                }
            }
        }

        return image;
    }
};