class Solution {
public:

    void rec(vector<vector<int>>& answer,vector<int>& candidates, int target,int index,vector<int>& output) {

        if( index == candidates.size()){
            if( target == 0 ){
                answer.push_back(output);
            }
            return;
        }

        if(candidates[index] <= target){
            output.push_back(candidates[index]);
            rec(answer,candidates,target-candidates[index],index,output);
            output.pop_back();
        }

        rec(answer,candidates,target,index+1,output);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> output;

        rec(answer,candidates,target,0, output);

        return answer;

    }
};