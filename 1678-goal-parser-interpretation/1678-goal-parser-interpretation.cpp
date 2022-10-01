class Solution {
public:
    string interpret(string command) {
        string ans{};
        for(int i=0;i<command.size();i++){
            if(command[i] == 'G'){
                ans += command[i];
                continue;
            }
            if(command[i] == '(' && command[i+1] == ')'){
                ans += 'o';
                i+=1;
                continue;
            }
            else{
                ans+= "al";
                i+=3;
            }
            
        }
        return ans;
    }
};