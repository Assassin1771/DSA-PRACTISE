class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n=groupSizes.size();
        vector<vector<int>> res;
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({groupSizes[i],i});
        }
        
        sort(v.begin(),v.end());
        
        vector<int> temp;
        int count=0;
        for(int i=0;i<v.size();i++)
        {
            int x=v[i].first;
            
            if(x!=count)
            {
                count=x;
            }
            
            if(temp.size()<count)
            {
                temp.push_back(v[i].second);
                
                if(temp.size()==count)
                {
                    res.push_back(temp);
                    temp.clear();
                    count=0;
                }
            }
            
            // else
            // {
            //     res.push_back(temp);
            //     temp.clear();
            // }
        }
        
        return res;
        
        
    }
};