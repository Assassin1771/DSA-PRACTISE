class Solution {
public:
    
//     int solve(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp)
//     {
//         if(row==0 and col==0)
//             return grid[0][0];
        
//         if(row<0 or col<0)
//             return 1e9;
        
//         if(dp[row][col]!=-1)
//             return dp[row][col];
        
//         int up=grid[row][col]+solve(row-1,col,grid,dp);
//         int left=grid[row][col]+solve(row,col-1,grid,dp);
        
//         return dp[row][col]=min(up,left);
//     }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                    dp[0][0]=grid[0][0];
                
                else
                {
                    int up=grid[i][j];
                    int left=grid[i][j];
                    
                    if(i>0)
                        up+=dp[i-1][j];
                    
                    else
                        up+=1e9;
                    
                    if(j>0)
                        left+=dp[i][j-1];
                    
                    else
                        left+=1e9;
                    
                    dp[i][j]=min(up,left);
                        
                }
            }
        }
        
        return dp[m-1][n-1];
        
    }
};