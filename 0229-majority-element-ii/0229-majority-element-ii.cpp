class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // Phase 1: Find potential candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
                continue;
            }
            if (num == candidate2) {
                count2++;
                continue;
            }
            if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
                continue;
            }
            if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
                continue;
            }
            count1--;
            count2--;
        }

        // Phase 2: Verify the candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> res;
        int n = nums.size();
        if (count1 > n / 3) res.push_back(candidate1);
        if (count2 > n / 3) res.push_back(candidate2);

        return res;
    }
};
