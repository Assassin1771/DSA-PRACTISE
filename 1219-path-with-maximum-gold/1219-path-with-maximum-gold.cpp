class Solution {
public:
    
    int dx[4]={-1,0,1,0}; // U,R,D,L
    int dy[4]={0,1,0,-1};
    
    bool isSafe(int x, int y, vector<vector<int>> &grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(x<0 or y<0 or x>=m or y>=n or grid[x][y]==-1 or grid[x][y]==0)
            return false;
        
        return true;
    }
    
    void fun(int x, int y, vector<vector<int>> &grid, int &sum, int &maxx)
    {
        if(!isSafe(x,y,grid))
            return;
        
        int original=grid[x][y];
        grid[x][y]=-1;
        
        
        for(int i=0;i<4;i++)
        {
            maxx+=original;
            // cout<<x<<" "<<y<<" "<<maxx<<" "<<sum<<endl;
            
            fun(x+dx[i],y+dy[i],grid,sum,maxx);
            
            sum=max(sum,maxx);
            maxx-=original;
        }      
        
        grid[x][y]=original;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int res=0;
        int sum=0,maxx=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    fun(i,j,grid,sum,maxx);
                    res=max(res,sum);
                    
                    // cout<<i<<" "<<j<<" "<<res<<endl;
                    sum=0;
                    maxx=0;
                }
            }
        }
        
        return res;
        
    }
};