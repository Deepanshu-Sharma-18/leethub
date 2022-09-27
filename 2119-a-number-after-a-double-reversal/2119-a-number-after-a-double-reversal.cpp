class Solution {
public:
    bool isSameAfterReversals(int num) {
        string a = to_string(num);
        reverse(a.begin(),a.end());
        
        int num1 = stoi(a);
        
        string a1 = to_string(num1);
        reverse(a1.begin(),a1.end());
        
        int num2 = stoi(a1);
        
        if(num == num2){
            return true;
        }
        
      return false;
        
    }
};