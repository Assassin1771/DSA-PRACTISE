class Solution {
public:
    
    int res=0;
    
    bool isSafe(vector<vector<char>> &grid, vector<vector<int>> &vis, int x, int y)
    {
        
        int m=grid.size();
        int n=grid[0].size();
        
        if(x>=m or x<0 or y>=n or y<0 or vis[x][y]==1 or grid[x][y]=='0')
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int x, int y)
    {
        if(!isSafe(grid,vis,x,y))
        return;
        
        vis[x][y]=1;
        
        dfs(grid,vis,x+1,y);
        dfs(grid,vis,x,y+1);
        dfs(grid,vis,x-1,y);
        dfs(grid,vis,x,y-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
                
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(grid[i][j]=='1' and vis[i][j]==0)
                {
                    dfs(grid,vis,i,j);         
                    res++;
                }   
            }
        }
        
        return res;
    }
};