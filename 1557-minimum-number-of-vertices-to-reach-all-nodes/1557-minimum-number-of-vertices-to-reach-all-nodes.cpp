class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> res;
        vector<int> indegree(n);
        
        for(auto i:edges)
        {
            int x=i[0];
            int y=i[1];
            
            indegree[y]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                res.push_back(i);
            
            // cout<<indegree[i]<<" ";
        }
        
        return res;
    }
};