class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0;
        int ans = 0;
        vector<int> lastSeen(3,-1);

        while(right < s.size()){
            lastSeen[s[right] - 'a'] = right;
            
           if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
                ans += minIndex + 1;
            }
            right++;      
        }

        return ans;
    }
};