class Solution {
public:
    
//     int minSum(int x, int y, vector<vector<int>> &mat, vector<vector<int>> &dp)
//     {
//         int n=mat.size();
//         if(y>=n or y<0)
//             return 1e9;
        
//         if(x==0)
//             return mat[x][y];
        
//         if(dp[x][y]!=-1)
//             return dp[x][y];
    
//         int up=mat[x][y]+minSum(x-1,y,mat,dp);
//         int left=mat[x][y]+minSum(x-1,y-1,mat,dp);
//         int right=mat[x][y]+minSum(x-1,y+1,mat,dp);
        
//         return dp[x][y]=min(up,min(left,right));
//     }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n=mat.size();
        
        vector<vector<int>> dp(n, vector<int> (n,-1));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=mat[0][i];
        }
        
        for(int x=1;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                int up=mat[x][y]+dp[x-1][y];
                int left=mat[x][y],right=mat[x][y];
                
                if(y>=1)
                    left+=dp[x-1][y-1];
                
                else
                    left+=1e9;
                
                if(y+1<n)
                    right+=dp[x-1][y+1];
                
                else
                    right+=1e9;

                dp[x][y]=min(up,min(left,right));   
            }
        }
        
        int res=1e9;
        for(int i=0;i<n;i++)
            res=min(res,dp[n-1][i]);
        
        return res;
    }
};