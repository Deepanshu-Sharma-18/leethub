class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
   
        vector<int> v;
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                
                    int a = j+1,b = nums.size()-1;
                    while(a < b){
                        if(nums[i] + nums[j] > (long long) target - (long long) nums[a] - (long long)nums[b]){
                            b--;
                        }
                        else if(nums[i] + nums[j] < (long long) target- (long long)nums[a] - (long long)nums[b]){
                            a++;
                        }else{
                            
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[b]);
                            v.push_back(nums[a]);
                            sort(v.begin(),v.end());
                            st.insert(v);
                            a++;
                            b--;
                            v.clear();
                        }
                        
                    }
                
            }   
        }
        for(auto a: st){
            ans.push_back(a);
        }



        return ans;
    }
};