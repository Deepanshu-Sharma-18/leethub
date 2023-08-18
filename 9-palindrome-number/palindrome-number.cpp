class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0) return false;
        long int y=0;
        int z =x;


        while(x>0){
            int temp = x%10;
            y = y*10 + temp;
            x/=10;
        }

        return y == z;
    }
};