class Solution {
public:
    int secondHighest(string s) {
        int arr[10] = {0};
        for(auto it : s){
            if(it >= '0' && it <= '9'){
                arr[it -'0']++;
            }
        }

        bool f = false;
        for(int i=9; i>=0; i--){
            if(arr[i] > 0){
                if(f) return i;
                f = true;
            }
        }
        return -1;
    }
};