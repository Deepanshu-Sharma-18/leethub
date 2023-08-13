
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
       map<int,int> mp;
       set<vector<int>> st;
       vector<int>v;
        

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(mp.find(0 - nums[i]-nums[j]) != mp.end()){
                    
              
                    if(i != j && j!=mp[ - nums[i]-nums[j]] && i!=mp[ - nums[i]-nums[j]]){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(-nums[i]-nums[j]);
                        sort(v.begin(),v.end());
                        st.insert(v);
                        v.clear();
                         
                    }
                     
                }
                mp[nums[j]] = j;
            }
            
        }

        for(auto a : st){
            ans.push_back(a);
        }


        return ans;
       
    }
};