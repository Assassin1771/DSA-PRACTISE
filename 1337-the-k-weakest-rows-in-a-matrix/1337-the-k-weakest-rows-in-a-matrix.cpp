class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int> res;
        
        set<pair<int,int>> st;
        
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            
            // cout<<count<<endl;
        
            st.insert({count,i});    
            count=0;
        }
        
        for(auto i:st)
        {
            if(k)
            {
                res.push_back(i.second);
                k--;
            }        
        }
        
        
        return res;
        
    }
};