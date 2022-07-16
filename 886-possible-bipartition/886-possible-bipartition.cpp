class Solution {
public:
    
    bool checkBipartite(vector<int> adj[], int s, vector<int> &color)
    {
        queue<int> q;
        color[s]=1;
        
        q.push(s);
        
        while(q.size())
        {
            int curr=q.front();
            q.pop();
            
            for(auto i:adj[curr])
            {
                if(color[i]==-1)
                {
                    color[i]=1-color[curr];
                    q.push(i);
                }
                
                else if(color[i]==color[curr])
                    return false;
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> adj[n+1];
        
        for(auto i:dislikes)
        {
            int first=i[0];
            int second=i[1];
            
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!checkBipartite(adj,i,color))
                    return false;
            }
        }
        
        return true;
        
    }
};