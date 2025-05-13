class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long left = INT_MAX, right = INT_MIN;

        for(auto it : bloomDay){
            if(it > right){
                right = it;
            }

            if(it < left){
                left = it;
            }
        }

        right *= m;

        int ans  = -1;

        while(left <= right){
            long long mid = left + (right - left)/2;

            int count = 0;
            int boq = 0;

            for(auto it : bloomDay){
                if(count >= k){
                    boq++;
                    count = 0;
                }
                if(it <= mid){
                    count++;

                }else{
                    count = 0;
                }
            }
            if(count >= k){
                boq++;
            }

            if(boq >= m){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};