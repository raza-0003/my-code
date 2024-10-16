class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NLE(n,n);
        vector<int> PLE(n,-1);
        stack<int>st;
        //individually calculate nle (calculating next least element)
         //calculating ple(previous less element)
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            PLE[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                NLE[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
       
        long long result = 0;
        long long MOD = 1e9+7;
        for(int i=0;i<n;i++){
            long long left = (i - PLE[i]);
            long long right = NLE[i] - i;
            result = (result + arr[i] * left * right) % MOD;
        }
        return result;
    }
};