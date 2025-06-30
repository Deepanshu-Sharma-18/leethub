class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool f = false;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] >= newInterval[0]){
                intervals.insert(intervals.begin() + i, newInterval);
                f = true;
                break;
            }
        }

        if(!f) intervals.push_back(newInterval);

        int i=1;

        while(i < intervals.size()){
            if(intervals[i][0] <= intervals[i-1][1]){
                intervals[i][0] = min(intervals[i][0] , intervals[i-1][0]);
                intervals[i][1] = max(intervals[i][1] , intervals[i-1][1]);

                intervals.erase(intervals.begin() + i - 1);
                i--;
            }
            i++;
        }

        return intervals;
    }
};