class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n=costs.size();
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            int temp=costs[i][0]-costs[i][1];
            v.push_back({temp,i});
        }
        
        sort(v.begin(),v.end());
        
        int res=0;
        int half=n/2;
        for(int i=0;i<n;i++)
        {
            if(half)
            {
                auto it=v[i];
                int ind=v[i].second;
                
                res+=costs[ind][0];
                half--;
            }
            
            else
            {
                auto it=v[i];
                int ind=v[i].second;
                
                res+=costs[ind][1];
            }
        }
        
        return res;
        
    }
};