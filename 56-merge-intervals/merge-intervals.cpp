class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        int a = intervals[0][0]  , b= intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if( b >= intervals[i][0] || b >= intervals[i][1]){
                a = min(a , intervals[i][0]);
                b = max(intervals[i][1] , b);
            }else{
                ans.push_back({a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        ans.push_back({a,b});

        return ans;
    }
};