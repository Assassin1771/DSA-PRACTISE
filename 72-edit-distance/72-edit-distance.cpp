class Solution {
public:
    
    int count(int i,int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(i<0)
            return j+1;
        
        if(j<0)
            return i+1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(s1[i]==s2[j])
            return count(i-1,j-1,s1,s2,dp);
        
        int insert=1+count(i,j-1,s1,s2,dp);
        int remove=1+count(i-1,j,s1,s2,dp);
        int replace=1+count(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]= min(insert,min(remove,replace));
    }
    
    int minDistance(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        return count(m-1,n-1,s1,s2,dp);
        
    }
};