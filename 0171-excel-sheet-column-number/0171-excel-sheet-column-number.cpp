class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i=0; i<columnTitle.size()-1; i++){
            ans += pow(26, columnTitle.size() - i -1) * (columnTitle[i] - 'A' + 1);
        }
        ans += (columnTitle[columnTitle.size()-1] - 'A' + 1);

        return ans;
    }
};