class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
      int curr = arr[0];
      int i = 1;
        arr.push_back(INT_MIN);
      while(i < arr.size() && arr[i] != INT_MIN){
        if(arr[i] == curr){
            int j = i;
            while(j < arr.size() && arr[j]!= INT_MIN){
                arr[j] = arr[j+1];
                j++;
            }
           
        }else{
            curr = arr[i];
            i++;
        }
      }

      return i;
    }
};