class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int> res(n);
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(st.empty()==false and arr[i]>arr[st.top()])
            {
                res[st.top()]=abs(i-st.top());
                st.pop();
            }
            
            st.push(i);
        }
        
        return res;
        
    }
};