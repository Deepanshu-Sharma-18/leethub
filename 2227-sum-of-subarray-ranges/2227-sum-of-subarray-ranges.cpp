class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        vector<int> pse,nse,pge,nge;

        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            pse.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            pge.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=nums.size()-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            nse.push_back(st.empty() ? nums.size() : st.top());
            st.push(i);
        }

        while(!st.empty()) st.pop();
        reverse(nse.begin(), nse.end());
        
        for(int i=nums.size()-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            nge.push_back(st.empty() ? nums.size() : st.top());
            st.push(i);
        }

        while(!st.empty()) st.pop();
        reverse(nge.begin(), nge.end());

        long long minSum = 0;
        long long maxSum = 0;

        for(int i=0; i<nums.size(); i++){
           long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            minSum += (leftMin * rightMin) * (long long)nums[i];
            maxSum += (leftMax * rightMax) * (long long)nums[i];
        }

        return maxSum - minSum;
        
    }
};