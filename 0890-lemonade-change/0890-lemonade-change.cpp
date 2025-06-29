class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;

        for(auto it : bills){
            if(it == 5) fives++;
            else if(it == 10){
                tens++;
                if(fives < 1) return false;
                fives--;
            }else{
                if(tens >= 1){
                    tens -= 1;
                    if(fives < 1) return false;
                    fives--;
                }else{
                    if(fives < 3) return false;
                    fives -= 3;
                }
            }
        }

        return true;
    }
};