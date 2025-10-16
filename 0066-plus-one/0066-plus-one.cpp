class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        if(digits[n] < 9){
            digits[n]++;
        }else{
            while(n >= 0 && digits[n] == 9){
                digits[n] = 0;
                n--;
            }
            if(n >= 0){
                digits[n]++;
            }
            else{
                digits.insert(digits.begin(), 1);
            }
        }

        return digits;
    }
};