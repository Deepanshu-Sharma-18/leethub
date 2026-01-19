class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int q = -1;
        int x = -1, y = -1;

        for(auto it : towers){
            int d = abs(it[0] - center[0]) + abs(it[1] - center[1]);
            if(d <= radius){
                if(q < it[2]){
                    q = it[2];
                    x = it[0];
                    y = it[1];
                }else if(q == it[2]){
                    if(x > it[0]){
                        x = it[0];
                        y = it[1];
                    }else if(x == it[0] && y > it[1]){
                        x = it[0];
                        y = it[1];
                    }
                }
            }
        }

        return {x , y}; 
    }
};