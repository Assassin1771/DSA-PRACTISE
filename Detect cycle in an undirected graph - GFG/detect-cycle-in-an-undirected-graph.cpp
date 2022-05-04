// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs(vector<int> adj[], vector<int> &vis, int s, int v)
    {
        vis[s]=1;
        
        queue<pair<int,int>> q;
        q.push({s,-1});
        
        while(q.size())
        {
            int curr_val=q.front().first;
            int curr_prev=q.front().second;
            
            q.pop();
            
            for(auto i:adj[curr_val])
            {
                if(!vis[i])
                {
                    vis[i]=1;
                    q.push({i,curr_val});
                }
                
                else if(i!=curr_prev)
                {
                    return true;
                }
            }
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
                if(bfs(adj,vis,i,v))
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