class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
      int curr = arr[0];
      int i = 1;
      int count = 1;
      while(i < arr.size()){
        if(arr[i] == curr){
            arr[i] = INT_MAX;
        }else{
            curr = arr[i];
            count++;
        }
        i++;
      }

      sort(arr.begin() ,arr.end());

      return count;
    }
};