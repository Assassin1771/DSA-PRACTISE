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
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(pq.size())
        {
            int curr_key=pq.top().first;
            int curr_node=pq.top().second;
            
            pq.pop();
            
            mst[curr_node]=true;
            
            for(auto i:adj[curr_node])
            {
                int next_node=i[0];
                int next_dist=i[1];
                
                if(mst[next_node]==false and key[next_node]>next_dist)
                {
                    parent[next_node]=curr_node;
                    key[next_node]=next_dist;
                    
                    pq.push({next_dist, next_node});
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