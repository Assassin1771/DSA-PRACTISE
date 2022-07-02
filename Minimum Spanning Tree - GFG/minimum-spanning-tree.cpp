// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        
        vector<int> key(v,1e9);
        vector<bool> mst(v,false);
        vector<int> parent(v,-1);
        
        key[0]=0;
        
        for(int i=0;i<v-1;i++)
        {
            int minn=1e9+7, min_index=-1;
            for(int j=0;j<v;j++)
            {
                if(mst[j]==false and key[j]<minn)
                {
                    minn=key[j];
                    min_index=j;
                }
            }
            
            mst[min_index]=true;
            
            for(auto j:adj[min_index])
            {
                int next_node=j[0];
                int next_dist=j[1];
                
                if(mst[next_node]==false and next_dist<key[next_node])
                {
                    parent[next_node]=min_index;
                    key[next_node]=next_dist;
                }
            }
        }
    
        int sum=0;
        for(auto i:key)
        sum+=i;
        
        return sum;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends