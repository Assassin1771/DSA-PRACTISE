class Solution {
public:
    
    int dx[8]={0,1,1,1,0,-1,-1,-1};
    int dy[8]={1,1,0,-1,-1,-1,0,1};
    
    bool isSafe(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int n=grid.size();
        
        if(x<0 or x>=n or y<0 or y>=n or grid[x][y]==1 or vis[x][y]==1)
            return false;

        vis[x][y]=1;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        if(grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int res=0;
        while(q.size())
        {
            int count=q.size();
            
            for(int i=0;i<count;i++)
            {
                auto curr=q.front();
                q.pop();
                
                if(curr.first==n-1 and curr.second==n-1)
                    return res+1;
                
                for(int i=0;i<8;i++)
                {
                    if(isSafe(curr.first+dx[i],curr.second+dy[i],grid,vis))
                    {                        
                        // cout<<curr.first+dx[i]<<" "<<curr.second+dy[i]<<endl;
                        vis[curr.first][curr.second]=1;
                        q.push({curr.first+dx[i],curr.second+dy[i]});
                    }
                }    
            }
            
            res++;
        }
        
        return -1;
        
    }
};