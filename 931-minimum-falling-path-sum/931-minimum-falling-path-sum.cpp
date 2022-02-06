class Solution {
public:
    
    int solve(int row,int col,vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        int n=matrix.size();
        if(col<0 or col>=n)
            return 1e9;
        
        if(row==0)
            return matrix[row][col];
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int up=matrix[row][col]+solve(row-1,col,matrix,dp);
        int left=matrix[row][col]+solve(row-1,col-1,matrix,dp);
        int right=matrix[row][col]+solve(row-1,col+1,matrix,dp);
        
        return dp[row][col]=min(up,min(left,right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=matrix[i][j]+dp[i-1][j];
                int left=matrix[i][j];
                int right=matrix[i][j];
                
                if(j-1>=0)
                    left+=dp[i-1][j-1];
                
                else
                    left+=1e9;
                
                if(j+1<n)
                    right+=dp[i-1][j+1];
                    
                else
                    right+=1e9;
                
                dp[i][j]=min(up,min(left,right));
            }
        }
        
        int minn=1e9;
        for(int i=0;i<n;i++)
            minn=min(minn,dp[n-1][i]);
    
        return minn;
        
    }
};