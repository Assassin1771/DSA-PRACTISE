class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        
        int n=rocks.size();
        vector<int> temp;
        
        for(int i=0;i<n;i++)
        {
            int x=capacity[i]-rocks[i];
            temp.push_back(x);
        }
            
        sort(temp.begin(),temp.end());
        // for(auto i:temp)
        //     cout<<i<<endl;    
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(temp[i]==0)
                res++;
            
            if(add>0)
            {    
                if(temp[i]>0)
                {
                    if(add>=temp[i])
                    {
                        add-=temp[i];
                        // cout<<1111<<endl;
                        res++;    
                    }
                }
            }
        }
        
        return res;
        
    }
};