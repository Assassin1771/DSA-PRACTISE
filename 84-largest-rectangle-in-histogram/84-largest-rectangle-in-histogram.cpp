class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        
        vector<int> left_smaller(n,0), right_smaller(n,0);
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(st.size() and heights[st.top()]>heights[i])
            {
                right_smaller[st.top()]=i-1;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(st.size())
        {
            right_smaller[st.top()]=n-1;
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() and heights[st.top()]>heights[i])
            {
                left_smaller[st.top()]=i+1;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(st.size())
        {
            left_smaller[st.top()]=0;
            st.pop();
        }

        int res=0;
        for(int i=0;i<n;i++)
        {
            int temp=abs(right_smaller[i]-left_smaller[i]+1)*heights[i];
            res=max(res,temp);
        }
        
        return res;
    }
};