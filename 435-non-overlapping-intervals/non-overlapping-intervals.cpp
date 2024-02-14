class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count= 0;
        sort(intervals.begin(),intervals.end(),cmp);

        int a = intervals[0][0]  , b= intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if( b > intervals[i][0] ){
                count++;
                
            }else{
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }

        return count;
    }
};