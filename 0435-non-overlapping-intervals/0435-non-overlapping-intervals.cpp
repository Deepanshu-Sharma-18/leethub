class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < intervals[i-1][1]){
                intervals[i][1] = min(intervals[i][1] , intervals[i-1][1]);
                cnt++;
            }
        }

        return cnt;
    }
};