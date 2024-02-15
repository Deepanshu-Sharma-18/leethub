class Solution {
public:
    int candy(vector<int>& ratings) {
        int num = 0;
        int size = ratings.size();
        vector<int> mp(size,0);

        for(int i=1;i<size;i++){
           
                if(ratings[i-1] < ratings[i]){
                    mp[i] = mp[i-1]+ 1;
                }
        }

        for(int i=size-1;i>0;i--){
            
                if(ratings[i-1] > ratings[i]){
                    mp[i-1] = max(mp[i] + 1 , mp[i-1] ) ;
                }
            
        }

        for(int i=0;i<ratings.size();i++){
            num += mp[i];
        }

        return num + ratings.size();
    }
};



//first and last -- sirf ek neighbour consider

//middle mai 2 neighbours