class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        ans.push_back(intervals[0]);

        int k = 0;

        for(int i = 1; i < intervals.size();i++){
            if(intervals[i][0] <= ans[k][1]){
                ans[k][1] = max(ans[k][1] , intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
                k++;
            }
        }

        return ans;
    }
};