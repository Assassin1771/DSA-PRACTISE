// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        
        vector<int> dist(v,INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        dist[s]=0;
        pq.push({0,s});
    
        while(pq.size())
        {
            int curr_dist=pq.top().first;
            int curr_node=pq.top().second;
            
            pq.pop();
            
            for(auto it:adj[curr_node])
            {
                int next_node=it[0];
                int next_dist=it[1];
                
                if(curr_dist+next_dist<dist[next_node])
                {
                    dist[next_node]=curr_dist+next_dist;
                    pq.push({dist[next_node],next_node});
                }
            }
            
        }
        
        return dist;
        
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends