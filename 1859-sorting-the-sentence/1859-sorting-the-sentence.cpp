class Solution {
public:
    string sortSentence(string s) {
        string ans{};
        string temp{};
       // reverse(s.begin(),s.end());
        
        int c=1;
        for(auto val : s){
            if(val == ' '){
                c++;
            }
        }
        int n=1;
        
        for(int i=0;n<= c;i++){
            if(s[i] == ' '){
              temp="";  
                continue;
            }  
             
            if(s[i]-48 == n){
                ans+=temp + " ";
                n++;
                
            }
            temp+=s[i];
            
           if(i == s.size()-1){
               temp="";
               i = -1;
           }
                
                
        }
        ans.pop_back();
        return ans;
    }
};