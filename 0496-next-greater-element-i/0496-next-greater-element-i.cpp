class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int,int> mp;
        for(int j = nums2.size()-1; j >=0 ; j--){
            while(!s.empty()){
                if(nums2[j] < s.top()){
                    mp[nums2[j]] = s.top();
                    break;
                }
                s.pop();
            }

            if(s.empty()){
                mp[nums2[j]] = -1;
            }

            s.push(nums2[j]);

        }

        for(int i =0;i<nums1.size();i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};