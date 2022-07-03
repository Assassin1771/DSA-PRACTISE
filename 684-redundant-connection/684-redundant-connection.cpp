class Solution {
public:
    
    void dfs(int s, vector<int> &vis, vector<int> adj[], int x, int y)
    {
        // cout<<s<<endl;
        vis[s]=1;
        
        for(auto i:adj[s])
        {   
            if((s==x and i==y) or (s==y and i==x))
            {
                continue;
            }
            
            if(vis[i]==0)
                dfs(i,vis,adj,x,y);
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        
        vector<int> adj[n+1];
        for(auto i:edges)
        {
            int x=i[0];
            int y=i[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<int> vis(n+1,0);
        int a=-1,b=-1;
                        
        for(auto i:edges)
        {
            int x=i[0];
            int y=i[1];
            
            dfs(x,vis,adj,x,y);
            
            // for(int i=1;i<n+1;i++)
            // {
            //     if()
            // }
            
            if(vis[y]!=0)
            {
                a=x;
                b=y;
            }
            
            for(int i=0;i<n+1;i++)
                vis[i]=0;
        }
        
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        
        return res;
        
    }
};