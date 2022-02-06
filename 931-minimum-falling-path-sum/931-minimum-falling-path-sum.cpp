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
        
        int minn=1e9;
        for(int i=0;i<n;i++)
        {
            int temp=solve(n-1,i,matrix,dp);
            minn=min(minn,temp);
        }
        
        return minn;
        
    }
};