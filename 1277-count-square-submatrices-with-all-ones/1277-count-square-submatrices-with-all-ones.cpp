class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++)
            dp[i][0]=mat[i][0];
        
        for(int i=0;i<n;i++)
            dp[0][i]=mat[0][i];
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(mat[i][j]==0)
                    dp[i][j]=0;
                
                else
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // cout<<dp[i][j]<<" ";
                res+=dp[i][j];
            }
            
            // cout<<endl;
        }
        
        return res;
        
    }
};