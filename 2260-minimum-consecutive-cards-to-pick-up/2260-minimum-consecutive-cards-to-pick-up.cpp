class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int n=cards.size();
        
        int res=INT_MAX;
        
        vector<pair<int,int>> v;
        for(int i=0;i<cards.size();i++)
        {
            v.push_back({cards[i],i});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=1;i<v.size();i++)
        {
            int prev_first=v[i-1].first;
            int prev_second=v[i-1].second;
            
            int curr_first=v[i].first;
            int curr_second=v[i].second;
            
            if(prev_first==curr_first)
            {
                res=min(res,abs(curr_second-prev_second));
            }
        }    
        
        return (res==INT_MAX?-1:res+1);
        
        
    }
};