class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isSafe(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(x<0 or y<0 or x>=m or y>=n or grid[x][y]==0 or vis[x][y]==1)
            return false;
        
        return true;
    }
    
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, int &temp)
    {
        if(!isSafe(x,y,grid,vis))
            return;
        
        vis[x][y]=1;
        temp++;
        
        for(int i=0;i<4;i++)
            dfs(x+dx[i],y+dy[i],grid,vis,temp);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int> (n,0));
        
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    int temp=0;
                    dfs(i,j,grid,vis,temp);
                    
                    res=max(res,temp);
                    temp=0;
                }
                    
            }
        }
        
        return res;
    }
};