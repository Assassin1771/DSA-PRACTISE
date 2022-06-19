class Solution {
public:
    string removeDuplicates(string s) {
        
        int n=s.length();
        
        stack<char> st;
        st.push(s[0]);
        
        for(int i=1;i<n;i++)
        {
            if(st.size() and st.top()==s[i])
                st.pop();
            
            else
                st.push(s[i]);
        }
        
        string res="";
        while(st.size())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};