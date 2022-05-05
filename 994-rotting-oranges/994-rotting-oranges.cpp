class Solution {
public:
    
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
    bool isSafe(vector<vector<int>> &grid, vector<vector<int>> &vis, int x, int y)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(x<0 or x>=m or y<0 or y>=n or vis[x][y]==1 or grid[x][y]==0 or grid[x][y]==2)
            return false;
        
        // vis[x][y]=1;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m, vector<int> (n,0));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    count++;
            }
        }
        
        if(count==0)
            return 0;
        
        int res=0;
        while(q.size())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                auto curr=q.front();
                q.pop();
                
                int first=curr.first;
                int second=curr.second;
                
                grid[first][second]=2;
                
                // cout<<"A "<<first<<" "<<second<<' ';
                
                for(int i=0;i<4;i++)
                {
                    if(!isSafe(grid,vis,first+dx[i],second+dy[i]))
                        continue;
                    
                    // cout<<first+dx[i]<<" "<<second+dy[i]<<endl;
                    
                    q.push({first+dx[i],second+dy[i]});
                    vis[first+dx[i]][second+dy[i]]=1;
                }
            }
            
            res++;
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return res-1;
        
    }
};