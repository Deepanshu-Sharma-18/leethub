class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;
                
                int mini = INT_MAX, maxi = INT_MIN;
                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        mini = min(mini, freq[k]);
                        maxi = max(maxi, freq[k]);
                    }
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};
