class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            for(int j=0;j<ranges.size();j++){
    
                  if(ranges[j][0]<=i && i<=ranges[j][1]){
                    ans=1;
                      break;
                }  
                
                
            }
            
            if(ans==1){
                ans=0;
                continue;
            }
            else
                return false;
            }
        return true;
    
    }
};