class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1 && flowerbed[0] == 0) return 1;
        int ans = 0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i] == 1) continue;
            if(i == 0 && i+1 <= flowerbed.size()-1){
                if(flowerbed[i+1] != 1){
                    ans++;
                    flowerbed[i] = 1;
                } 
                continue;
            }
            if(i == flowerbed.size()-1 && i-1 >=0){
                if(flowerbed[i-1] != 1) ans++;
                continue;
            }

            if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                ans++;
            }
        }
        return ans >= n;
    }
};