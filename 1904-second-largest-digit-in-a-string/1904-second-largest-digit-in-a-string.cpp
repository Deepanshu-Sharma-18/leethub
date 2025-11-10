class Solution {
public:
    int secondHighest(string s) {
        // int arr[10] = {0};
        // for(auto it : s){
        //     if(it >= '0' && it <= '9'){
        //         arr[it -'0']++;
        //     }
        // }

        // bool f = false;
        // for(int i=9; i>=0; i--){
        //     if(arr[i] > 0){
        //         if(f) return i;
        //         f = true;
        //     }
        // }
        // return -1;
        int fm = -1, sm = -1;
         for(auto it : s){
            if(it >= '0' && it <= '9'){
                if(it - '0' < fm){
                    sm = max(sm , it - '0');
                }else if(it - '0' > fm){
                    sm = fm;
                    fm = it - '0';
                }
            }
        }

        return sm;
    }
};