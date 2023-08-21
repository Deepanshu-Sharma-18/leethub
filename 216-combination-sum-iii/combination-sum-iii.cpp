class Solution {
public:

    void rec(int index,set<vector<int>>& ans,vector<int> out , int k , int n){
        if( k == 0 ){
            if( n == 0){
                sort(out.begin(),out.end());
                ans.insert(out);
            }
            return;
        }

        if(n<0) return;

        for(int i=index;i<10;i++){
            out.push_back(i);
            rec(i+1,ans,out,k-1,n-i);
            out.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ans;
        vector<int> out;

        rec(1,ans,out,k,n);

        vector<vector<int>> result;
        for(auto i: ans){
            result.push_back(i);
        }

        return result;
    }
};