class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int c = arr.size() * 5 / 100;
        
        double sum =0;
        for(int i = c;i< arr.size() - c;i++){
            sum += arr[i];
        }
        
        double ans = sum/(arr.size()-2*c);
        
        return ans;
    }
};