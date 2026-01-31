class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size()-1;
        char ans = 'z' + 1;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(letters[mid] <= target){
                l = mid + 1;
            }else{
                ans = min(ans, letters[mid]);
                r = mid - 1;
            }
        }

        if(ans == 'z' + 1) return letters[0];

        return ans;
    }
};