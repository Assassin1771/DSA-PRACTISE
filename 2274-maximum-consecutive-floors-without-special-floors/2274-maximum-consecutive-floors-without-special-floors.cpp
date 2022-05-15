class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        int n=special.size();
        sort(special.begin(),special.end());
        
        int res=0;
        int i=bottom;
        
        for(int j=0;j<n;j++)
        {
            int temp=special[j]-i;
            res=max(res,temp);
            
            i=special[j]+1;
        }
        
        res=max(res,top-i+1);
        return res;
        
        
    }
};