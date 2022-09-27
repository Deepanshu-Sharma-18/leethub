class Solution {
public:
    string convertToTitle(int columnNumber) {
        int temp = columnNumber;
        int rem;
        string ans {};
        while(temp > 26){
            rem= temp%26; 
            if(rem==0){
          
                 ans+=(26+64);
                temp=temp-26;
                
            }else{
                            
                ans+=(rem+64);
            }
           
            temp/=26;

        }
        
        ans+=(temp+64);
        
        reverse(ans.begin(),ans.end());
        return ans;      
    }
};