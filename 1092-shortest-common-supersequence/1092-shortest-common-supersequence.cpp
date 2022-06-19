class Solution {
public:
    
//     int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
//     {        
//         if(s1<0 or s2<0)
//             return 0;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         if(s1[i]==s2[j])
//             return dp[i][j]= 1+lcs(i-1,j-1,s1,s2);
        
//         return dp[i][j]= max(lcs(i,j-1,s1,s2),lcs(i-1,j,s1,s2));
//     }
    
    string shortestCommonSupersequence(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        // cout<<dp[m][n];
        
        int x=m,y=n;
        string res="";
        while(x>0 and y>0)
        {
            if(s1[x-1]==s2[y-1])
            {
                res.push_back(s1[x-1]);
                x--;
                y--;
            }
            
            else if(dp[x-1][y]>dp[x][y-1])
            {
                res.push_back(s1[x-1]);
                x--;
            }
            
            else
            {
                res.push_back(s2[y-1]);
                y--;
            }
        }
        
        while(x)
        {
            res.push_back(s1[x-1]);
            x--;
        }
        
        while(y)
        {
            res.push_back(s2[y-1]);
            y--;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};