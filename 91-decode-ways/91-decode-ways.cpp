//https://leetcode.com/problems/decode-ways/discuss/740182/C%2B%2B-Recursion-or-Recursion-with-memoization-or-DP-Explained

class Solution {
public:
    
    int findWays(int ind, string &s, vector<int> &dp)
    {
        int n=s.length();
        
        if(ind<n and s[ind]=='0')
            return 0;
        
        if(ind==n-1 or ind==n)
            return 1;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        string s1=s.substr(ind,2);
        
        int way1=findWays(ind+1,s,dp);
        int way2=0;
        
        if(stoi(s1)>=1 and stoi(s1)<=26)
            way2+=findWays(ind+2,s,dp);
        
        return dp[ind]= way1+way2;
    }
    
    int numDecodings(string s) {
        
        vector<int> dp(s.length()+1,-1);
        return findWays(0,s,dp);
        
    }
};