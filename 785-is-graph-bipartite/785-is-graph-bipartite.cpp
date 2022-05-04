class Solution {
public:
    
    bool checkBipartite(vector<vector<int>> &graph, vector<int> &color, int s)
    {
        if(color[s]==-1)
        color[s]=1;
        
        for(auto it:graph[s])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[s];
                
                if(!checkBipartite(graph,color,it))
                    return false;
            }
            
            else if(color[it]==color[s])
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v=graph.size();
        
        vector<int> color(v,-1);
        
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(!checkBipartite(graph,color,i))
                    return false;
            }
        }
        
        return true;
        
    }
};