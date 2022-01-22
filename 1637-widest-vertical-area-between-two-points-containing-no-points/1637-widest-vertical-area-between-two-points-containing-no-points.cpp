class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        int n=points.size();
        
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(points[i][0]);
        }
        
        sort(v.begin(),v.end());
        
        int res=0;
        for(int i=1;i<v.size();i++)
        {
            res=max(res,abs(v[i]-v[i-1]));
        }
        
        return res;
        
    }
};