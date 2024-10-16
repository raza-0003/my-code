class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
           bool destroyed = false;
           while(!st.empty() && st.top()>0 && asteroids[i]<0){
            if(abs(asteroids[i])>st.top()){
                st.pop();
            }
            else if(abs(asteroids[i])==st.top()){
                st.pop();
                destroyed = true;
                break;
            }
            else{
                destroyed = true;
                break;
            }
           }
           if(!destroyed) st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};