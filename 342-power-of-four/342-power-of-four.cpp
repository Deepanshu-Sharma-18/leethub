class Solution {
public:
    bool isPowerOfFour(int n) {
        for(auto i=0;i<16;i++){
            if(n == pow(4,i))
                return true;
        }
        return false;
    }
};