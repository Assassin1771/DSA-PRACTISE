class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        vector<int> res(k);
        
        int m=logs.size();
        int n=2;
        
        map<int, set<int>> mp;
        
        for(int i=0;i<m;i++)
        {
            int a=logs[i][0];
            int b=logs[i][1];
            
            mp[a].insert(b);
        }
        
//         for(auto [x,y]:mp)
//         {
//             cout<<x<<" ";
            
//             for(auto j:y)
//                 cout<<j<<" ";
            
//             cout<<endl;
//         }
        
        for(auto [x,y]:mp)
        {
            int z=y.size();
            
            res[z-1]++;
        }
        
        return res;
        
    }
};