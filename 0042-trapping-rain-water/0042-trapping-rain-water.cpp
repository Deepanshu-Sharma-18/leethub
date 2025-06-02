class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        for(int i=0; i<height.size(); i++){
            while(!s.empty() && height[i] > height[s.top()]){
                int t = s.top();
                s.pop();

                if(s.empty()) break;
                
                int distance = i - s.top() - 1;
                int bounded_height = min(height[i], height[s.top()]) - height[t];
                ans += distance * bounded_height;
            }
            s.push(i);
        }
        return ans;
    }
};