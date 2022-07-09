class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isSafe(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(x<0 or y<0 or x>=m or y>=n or grid[x][y]==-1 or vis[x][y]==1)
            return false;
        
        return true;
    }
    
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> vis, int &res, int &walk, int walk1)
    {
        
        if(!isSafe(x,y,grid,vis))
        return;
    
        if(grid[x][y]==2)
        {
            walk1++;
            
            if(walk==walk1)
                res++;
            
            return;
        }
        
        vis[x][y]=1;  
        walk1++;
        
        for(int i=0;i<4;i++)
        {
            dfs(x+dx[i], y+dy[i], grid, vis,res,walk,walk1);
        }
        
        vis[x][y]=0;
        walk1--;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int> (n,0));
        int res=0;
        
        int x=-1,y=-1;
        int walk=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
                
                else if(grid[i][j]==0)
                    walk++;
            }
        }
        
        walk+=2;
        int currentWalk=0;
        dfs(x,y,grid,vis,res,walk,currentWalk);
        
        return res;
    }
};