class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int i=0;i<asteroids.size();i++){

            if(asteroids[i] < 0 && !s.empty() && s.top() > 0){
                bool a = false;
                while(!s.empty() &&s.top() > 0 ) {
                    if(abs(asteroids[i]) < abs(s.top())){
                        a = false;
                        break;
                    }else if(abs(asteroids[i]) == abs(s.top())){
                        s.pop();
                        a = false;
                        break;
                    }else{
                        s.pop();
                        a = true;
                    }
                }
                if(a) s.push(asteroids[i]);
            }else{
                s.push(asteroids[i]);
            }
            
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};