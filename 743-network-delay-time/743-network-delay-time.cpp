class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        int s=k;
        
        vector<int> dist(n+1,INT_MAX);
        dist[s]=0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
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
                    pq.push({dist[next_node],next_node});
                }
            }
        }
        
        int res=INT_MIN;
        for(int i=1;i<dist.size();i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            
            res=max(res,dist[i]);
        }
        
        return res;
        
        
        

        
    }
};