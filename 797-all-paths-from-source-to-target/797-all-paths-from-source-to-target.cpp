class Solution {
public:
    
    void dfs(int s, vector<int> adj[], vector<vector<int>> &res, vector<int> &temp, vector<int> &vis)
    {
        vis[s]=1;
        temp.push_back(s);
        
        // cout<<s<<endl;
        if(s==vis.size()-1)
        {
            res.push_back(temp);
            
            temp.pop_back();
            vis[s]=0;
            
            return;
        }
        
        for(auto i:adj[s])
        {
            if(vis[i]==0)
                dfs(i,adj,res,temp,vis);
        }
        
        vis[s]=0;
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int v=graph.size();
        
        vector<int> adj[v];
        
        for(int i=0;i<v;i++)
        {
            for(auto j:graph[i])
            {
                adj[i].push_back(j);
            }
        }
        
        vector<int> temp;
        vector<vector<int>> res;
        
        vector<int> vis(v,0);
        
        dfs(0,adj,res,temp,vis);
        
        return res;
    }
};