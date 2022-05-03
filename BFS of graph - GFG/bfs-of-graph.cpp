// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(vector<int> adj[],int s, vector<int> &vis, vector<int> &res)
    {
        vis[s]=1;
        
        queue<int> q;
        q.push(s);
        
        while(q.size())
        {
            int curr=q.front();
            q.pop();
            
            res.push_back(curr);
            
            for(auto x:adj[curr])
            {
                if(vis[x]==0)
                {
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        
    }
    
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(v,0);
        vector<int> res;
        
        // for(int i=0;i<v;i++)
        // {
        //     if(vis[i]==0)
        //     {
                
        //     }
        // }
        
        bfs(adj,0,vis,res);
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends