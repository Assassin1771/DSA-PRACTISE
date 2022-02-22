class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        set<pair<int,int>> s;
        
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            int a=intervals[i][0];
            int b=intervals[i][1];
            
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int c=intervals[j][0];
                    int d=intervals[j][1];
                    
                    if(a>=c and b<=d)
                    {
                        flag=false;
                        break;
                    }
                }
            }
            
            if(flag)
                s.insert({a,b});
            
            flag=true;
        }
        
        return s.size();
        
    }
};