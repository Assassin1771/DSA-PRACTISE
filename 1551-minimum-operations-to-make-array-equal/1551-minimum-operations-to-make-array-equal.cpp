class Solution {
public:
    int minOperations(int n) {
        
        if(n==1)
            return 0;
        
        if(n==2)
            return 1;
        
        vector<int> v(n);
        for(int i=0;i<n;i++)
            v[i]=(2*i)+1;
        
        int res=0;
        
        if(n%2==1)
        {
            int mid=n/2;
            int val=v[mid];
            
            for(int i=0;i<mid;i++)
            {
                res+=(v[mid]-v[i]);
            }
        }
        
        else
        {
            int mid=n/2;
            int val=v[mid]-1;
            
            for(int i=0;i<mid;i++)
            {
                res+=(val-v[i]);
            }
        }
        
        return res;
        
    }
};