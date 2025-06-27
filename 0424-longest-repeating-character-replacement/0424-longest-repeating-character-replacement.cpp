class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;

        int count = 0, ans = 0;
        vector<int> a(26, 0);

        while(right < s.size()){
            a[s[right] - 'A']++;

            count = max(count , a[s[right] - 'A']);

            while((right - left + 1) - count > k){
                a[s[left] - 'A']--;
                left++;
            } 

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};