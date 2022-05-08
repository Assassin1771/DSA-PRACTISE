class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double> dist(n,INT_MIN);
        dist[start]=0;
        
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        
        while(pq.size())
        {
            double curr_dist=pq.top().first;
            int curr_node=pq.top().second;
            
            pq.pop();
            
            for(auto it:adj[curr_node])
            {
                int next_node=it.first;
                double next_dist=it.second;
                
                if(curr_dist*next_dist>dist[next_node])
                {
                    dist[next_node]=curr_dist*next_dist;
                    pq.push({dist[next_node],next_node});
                }
            }
        }
        
        // for(auto i:dist)
        //     cout<<i<<" ";
        

        
        return (dist[end]==INT_MIN ? 0 : dist[end]);
        
    }
};