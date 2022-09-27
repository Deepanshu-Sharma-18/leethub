class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count{};
        
        for(int i=0;i<=n;i++){
            int num = i;
            while(num > 0){
                if(num%2 == 1)
                    count++;
                num/= 2;
                
            }
            ans.push_back(count);
            count=0;
        }
        return ans;
    }
};