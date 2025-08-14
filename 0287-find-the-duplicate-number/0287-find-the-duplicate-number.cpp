class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    
    // Phase 1: Find intersection point
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Phase 2: Find entrance to the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}

};