class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0;
        int ans = 0;

        for(int i=0; i<k; i++){
            leftSum += cardPoints[i];
        }

        ans = max(ans ,leftSum);

        for(int i = 0; i < k; i++){
            leftSum -= cardPoints[k - i - 1];
            rightSum += cardPoints[cardPoints.size() - i - 1];
            ans = max(ans, leftSum + rightSum);
        }


        return ans;

    }
};