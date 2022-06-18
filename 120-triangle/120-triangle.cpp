class Solution {
public:
    
//     int minSum(int x, int y, vector<vector<int>> &triangle, vector<vector<int>> &dp)
//     {
//         int n=triangle.size();
        
//         if(x==n-1)
//             return triangle[x][y];
        
//         if(dp[x][y]!=-1)
//             return dp[x][y];
        
//         int down=triangle[x][y]+minSum(x+1,y,triangle,dp);
//         int downD=triangle[x][y]+minSum(x+1,y+1,triangle,dp);
        
//         return dp[x][y]=min(down,downD);
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        
        vector<vector<int>> dp(n, vector<int> (n,-1));
        
        for(int i=0;i<n;i++)
        {
            dp[n-1][i]=triangle[n-1][i];
        }
        
        for(int x=n-2;x>=0;x--)
        {
            for(int y=x;y>=0;y--)
            {
                int down=triangle[x][y]+dp[x+1][y];
                int downD=triangle[x][y]+dp[x+1][y+1];

                dp[x][y]=min(down,downD);
            }
        }
        
        return dp[0][0];
        
    }
};