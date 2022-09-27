class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        if(low%2 == 1){
            if(high%2==1){
               return ((high-low)/2) +1;
            }else{
                 return ((high+1-low)/2);
            }
        }else{
            if(high%2==1){
                 return (high-low+1)/2;
            }else{
                 return (high-low)/2;
            }
        }
        return count;
    }
};