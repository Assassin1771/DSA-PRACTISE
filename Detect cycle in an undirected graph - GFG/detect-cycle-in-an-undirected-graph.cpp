// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int> adj[], vector<int> &vis, int s, int prev, int v)
    {
        vis[s]=1;
        
        for(auto i:adj[s])
        {
            if(vis[i]==0)
            {
                if(dfs(adj,vis,i,s,v))
                return true;
            }
            
            else if(i!=prev)
            return true;
        }
        
        return false;
    }
    
    
    
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(v,0);
        
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,i,-1,v))
                return true;
            }
        }
        
        return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends