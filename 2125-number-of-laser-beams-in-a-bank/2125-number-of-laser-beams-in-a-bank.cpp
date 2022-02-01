class Solution {
public:
    
    int count(string s)
    {
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                res++;
        }
        
        return res;
    }
    
    int numberOfBeams(vector<string>& bank) {
        
        int n=bank.size();
        int res=0;
        
        bool flag1=false,flag2=false;
        int temp1=0,temp2=0;
        
        for(int i=0;i<n;i++)
        {
            string s=bank[i];
            int x=count(s);
            
            // cout<<x<<endl;
            
            if(flag1==false and x>0)
            {
                flag1=true;
                temp1=x;
            }
            
            else if(flag2==false and x>0)
            {
                flag2=true;
                temp2=x;
            }
            
            if(flag1==true and flag2==true)
            {
                res+=(temp1*temp2);
                temp1=temp2;
                temp2=0;
                
                flag1=true;
                flag2=false;
            }
        }
        
        return res;
        
    }
};