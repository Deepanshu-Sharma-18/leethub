class Solution {
public:
    string removeStars(string s) {
        int num = 0;

        string ans = "";

        for(int i=s.size()-1;i >=0 ; i--){
            if(s[i] == '*'){
                num++;
            }else{
                if(num >0){
                    num--;
                }else{
                    ans += s[i];
                }
            }
            
        }

         reverse(ans.begin() , ans.end());
         return ans;
    }
};