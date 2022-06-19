class Solution {
public:
    
    int count(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(j==0)
            return 1;
        
        if(i==0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i-1]==t[j-1])
            return dp[i][j]= count(i-1,j-1,s,t,dp)+count(i-1,j,s,t,dp);
            
        else
            return dp[i][j]= count(i-1,j,s,t,dp);
    }
    
    int numDistinct(string s, string t) {
        
        int m=s.length();
        int n=t.length();
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        return count(m,n,s,t,dp);
        
    }
};