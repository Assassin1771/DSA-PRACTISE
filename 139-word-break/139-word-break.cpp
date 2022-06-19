class Solution {
public:
    
    bool checkWordBreak(int ind, string &s, unordered_set<string> &st, unordered_map<int,bool> &dp)
    {
        int n=s.length();
        if(ind==n)
            return true;
        
        if(dp.count(ind))
            return dp[ind];
        
        for(int i=ind;i<n;i++)
        {
            if(st.count(s.substr(ind,i-ind+1)) and checkWordBreak(i+1,s,st,dp))
                return dp[ind]= true;
        }
        
        return dp[ind]= false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        
        unordered_set<string> st;
        unordered_map<int,bool> dp;
        
        for(auto i:wordDict)
            st.insert(i);
        
        return checkWordBreak(0,s,st,dp);
        
    }
};