class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n=people.size();
        int res=0;
        int temp=0;
        
        sort(people.begin(),people.end());
        
        int i=0,j=n-1;
        while(i<=j)
        {
            int temp=people[i]+people[j];
            
            if(temp<=limit)
            {
                res++;
                i++;
                j--;
            }
            
            else if(temp>limit)
            {
                res++;
                j--;
            }
        }
        
        return res;
        
    }
};