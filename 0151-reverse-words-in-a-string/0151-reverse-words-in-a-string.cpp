class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        string result = "";
        int active = false;
        for(auto it : s){
            if(it == ' ' && active){
                result += it;
                active = false;
                continue;
            }
            if(it == ' ' && !active) continue;

            active = true;
            result += it;
        }

        if(result[result.size()-1]== ' ') result.erase(result.size()-1);

        s = result;
        active = false;
        int i = 0;
        int j = 0;
        while(j < s.size()){
            if(s[j] == ' ' && !active){
                j++;
                continue;
            }

            if(s[j] == ' ' && active){
                reverse(s.begin() + i , s.begin() + j);
                j++;
                active = false;
            }else{
                if(!active){
                    i = j;
                    active = true;
                } 
                j++;
                
            }
        }

        reverse(s.begin() + i , s.begin() + j);


        return s;
    }
};