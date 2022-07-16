class Solution {
public:
    
    int mod=1e9+7;
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool outOfBounds(int x, int y, int m, int n)
    {
        
        if(x<0 or y<0 or x>=m or y>=n)
        {
            return true;
        }
        
        return false;
    }
    
    bool isSafe(int x, int y, int m, int n)
    {
        if(x<0 or x>=m or y<0 or y>=n)
            return false;
        
        return true;
    }
    
    int dfs(int x, int y, int m, int n, int moves, vector<vector<vector<int>>> &dp)
    {          
        if(outOfBounds(x,y,m,n))
            return 1;
        
        if(moves==0)
            return 0;
        
        if(!isSafe(x,y,m,n))
            return 0;
        
        if(dp[x][y][moves]!=-1)
            return dp[x][y][moves];
        
        int count=0;
        for(int i=0;i<4;i++)
        {
            count=(count+(dfs(x+dx[i],y+dy[i],m,n,moves-1, dp)) % (mod)) % (mod);
        }
        
        return dp[x][y][moves] = count;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove+1,-1)));
        
        return dfs(startRow, startColumn, m, n, maxMove, dp) % (int)(1e9+7);
    }
};