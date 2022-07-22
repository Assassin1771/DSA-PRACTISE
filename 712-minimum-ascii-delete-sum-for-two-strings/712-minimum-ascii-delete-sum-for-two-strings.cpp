class Solution {
public:
    
    int solve(int i, int j, string &s1, string &s2)
    {
        int m=s1.length();
        int n=s2.length();
        
        if(i==m and j==n)
            return 0;
        
        if(i==m)
        {
            int count=0;
            for(int k=j;k<n;k++)
                count+=(int)(s2[k]);
            
            return count;
        }
        
        if(j==n)
        {
            int count=0;
            for(int k=i;k<m;k++)
                count+=(int)(s1[k]);
            
            return count;
        }
        
        if(s1[i]==s2[j])
            return solve(i+1,j+1,s1,s2);
        
        else
            return min(s1[i]+solve(i+1,j,s1,s2),s2[j]+solve(i,j+1,s1,s2));
    }
    
    int minimumDeleteSum(string s1, string s2) {
     
        int m=s1.length();
        int n=s2.length();
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            dp[0][i]=dp[0][i-1]+s2[i-1];
        }
        
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=dp[i-1][0]+s1[i-1];
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
        
                else
                    dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
};