class Solution {
public:
    
    bool static comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]<b[0])
            return true;
        
        return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        
        sort(intervals.begin(),intervals.end(),comp);
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for(int i=1;i<n;i++)
        {
            vector<int> prev=res.back();
            vector<int> curr=intervals[i];
            
            if(prev[1]<curr[0])
                res.push_back(curr);
            
            else
            {
                res.pop_back();
                
                prev[1]=max(prev[1],curr[1]);
                res.push_back(prev);
            }
        }
        
        return res;
        
    }
};