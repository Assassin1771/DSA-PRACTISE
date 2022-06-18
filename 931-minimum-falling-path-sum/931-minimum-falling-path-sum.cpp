class Solution {
public:
    
    int minSum(int x, int y, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        int n=mat.size();
        if(y>=n or y<0)
            return 1e9;
        
        if(x==0)
            return mat[x][y];
        
        if(dp[x][y]!=-1)
            return dp[x][y];
    
        int up=mat[x][y]+minSum(x-1,y,mat,dp);
        int left=mat[x][y]+minSum(x-1,y-1,mat,dp);
        int right=mat[x][y]+minSum(x-1,y+1,mat,dp);
        
        return dp[x][y]=min(up,min(left,right));
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n=mat.size();
        
        vector<vector<int>> dp(n, vector<int> (n,-1));
        int res=1e9;
        for(int i=0;i<n;i++)
        {
            
            res=min(res,minSum(n-1,i,mat,dp));
            
            // dp.clear();
            // memset(dp,-1,sizeof(dp));
        }
        
        return res;
    }
};