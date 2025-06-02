class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        for(int j=nums.size()-1; j>=0; j--){
            s.push(nums[j]);
        }
        for(int j=nums.size()-1; j>=0; j--){
            int t = nums[j];
            while(!s.empty()){
                if(s.top() > nums[j]){
                    nums[j] = s.top();
                    break;
                }
                s.pop();
            }
            if(s.empty()) nums[j] = -1;
            s.push(t);
        }

        return nums;
    }
};