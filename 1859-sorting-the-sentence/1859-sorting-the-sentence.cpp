class Solution {
public:
    string sortSentence(string s) {
        
        int n=s.length();
        int len=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
                len++;
        }
        
        len++;
    
        string res="";
        
        vector<string> v(len);
        string temp;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {   
                
                char c=s[i-1];
                int x=(int)c;
                
                temp.pop_back();
                
                x-=48;
                v[x-1]=temp;
                temp="";
            }
            
            else
            {
                temp.push_back(s[i]);
            }
        }
        
        char c=s[n-1];
        int x=(int)c;
                
        temp.pop_back();
                
        x-=48;       
        v[x-1]=temp;
        temp="";
        
    
        for(auto i:v)
        {
            res+=i;
            res.push_back(' ');
        }
        
        res.pop_back();
        
        return res;
        
    }
};