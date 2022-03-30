class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n=s.length();
        string temp="";
        string res="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {   
                if(temp.size())
                {
                    res=temp;
                    temp.clear();
                }
            }
            
            else
            {
                temp.push_back(s[i]);
            }
            
            cout<<"R:"<<res<<" T:"<<temp<<endl;
        }
        
        if(temp.size())
            res=temp;
        
        cout<<"sdsd"<<res<<endl;
        
        return res.size();
        
    }
};