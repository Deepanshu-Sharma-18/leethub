class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        map<int,int> m1,m2;

        for(auto it: word1){
            m1[it]++;
        }

        for(auto it : word2){
            m2[it]++;
        }

        for(int i=0;i<word1.size();i++){
            if(m1.find(word2[i]) == m1.end()) return false;
            if(m2.find(word1[i]) == m2.end()) return false;
        }

        long int s1 =  1, s2 = 1;

        for(auto it: word1){
            s1 += m1[it];
        }

        for(auto it : word2){
            s2 += m2[it];
        }

        if(s1 != s2) return false;

        return true;
    }
};