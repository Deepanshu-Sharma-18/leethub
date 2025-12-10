class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> ct;
        vector<int> ans;

        int key = nums[0], count = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                count++;
            }else{
                ct.push_back({count, key});
                key = nums[i];
                count = 1;
            }
        }
        ct.push_back({count, key});
        sort(ct.begin(), ct.end(), greater<pair<int,int>>());
        for(int i=0; i<k; i++){
            ans.push_back(ct[i].second);
        }

        return ans;
    }
};