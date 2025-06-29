class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int l = 0, r = 0;
        int cnt = 0;
        while(r < nums.size() - 1){
            int maxi = 0;
            while(l <= r){
                maxi = max(maxi, l + nums[l]);
                l++;
            }

            l = r + 1;
            r =  maxi;
            cnt++;
        }

        return cnt;
    }
};