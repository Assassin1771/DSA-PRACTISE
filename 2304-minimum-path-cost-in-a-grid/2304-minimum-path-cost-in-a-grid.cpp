class Solution {
public:
    
    int findMinimumPathSum(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &moveCost, vector<vector<int>> &dp)
    {
        if(row==grid.size()-1)
            return grid[row][col];
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int minn=1e9;
        for(int i=0;i<grid[0].size();i++)
        {
            int curr_value=grid[row][col];
            int edge_value=moveCost[curr_value][i];
        
            int temp=0;
            
            temp=findMinimumPathSum(row+1,i,grid,moveCost,dp)+curr_value+edge_value;
            minn=min(minn,temp);
        }
        
        return dp[row][col]= minn;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n,-1));
            
        int res=1e9;
        for(int i=0;i<grid[0].size();i++)
        {
            res=min(res,findMinimumPathSum(0,i,grid,moveCost,dp));
        }
        
        return res;
        
    }
};