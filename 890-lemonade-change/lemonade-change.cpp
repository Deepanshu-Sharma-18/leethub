class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0 , ten = 0;

        for(int i=0 ; i< bills.size();i++){
            if(bills[i] == 5){
                five++;
                continue;
            }else{
                 
                if(bills[i] - 5 == 5){
                    ten++;
                }
                if(bills[i] - 5 == 5){
                    if(five >= 1){
                        five--;
                    }else{
                        return false;
                    }
                }else{
                    if (five >= 1 && ten >= 1){
                        five--;
                        ten--;
                        continue;
                    }
                    if(five >= 3){
                        five-= 3;
                        continue;
                    } 

                    return false;
                }
            }
        }

        return true;

    }
};