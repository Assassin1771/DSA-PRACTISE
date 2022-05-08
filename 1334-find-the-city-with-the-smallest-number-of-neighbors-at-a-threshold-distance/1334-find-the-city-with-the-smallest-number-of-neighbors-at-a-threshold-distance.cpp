class Solution {
public:
    
    bool static comp(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first<b.first)
            return true;
        
        if(a.first==b.first)
        {
            if(a.second>b.second)
                return true;
        }
        
        return false;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++)
        {
            int s=i;
            vector<int> dist(n,INT_MAX);
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
                    int next_node=it.first;
                    int next_dist=it.second;
                    
                    if(curr_dist+next_dist<dist[next_node])
                    {
                        dist[next_node]=curr_dist+next_dist;
                        pq.push({dist[next_node], next_node});
                    }
                }
            }
            
            int count=0;
            // cout<<i<<": ";
            for(int i=0;i<dist.size();i++)
            {
                if(dist[i]<=t)
                    count++;
                
                // cout<<dist[i]<<" ";
            }
            
            // cout<<endl;
            
            res.push_back({count,s});
            
            dist.clear();
        }
        
        sort(res.begin(),res.end(),comp);
        
        // for(auto i:res)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        return res[0].second;
        
    }
};