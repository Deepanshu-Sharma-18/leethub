class NumArray {
public:
    vector<int> num;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
            num.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return num[right] - (left > 0 ? num[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */