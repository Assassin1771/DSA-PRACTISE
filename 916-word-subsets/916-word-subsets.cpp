class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        int n=words2.size();
        
        vector<int> count(125);
        for(int i=0;i<n;i++)
        {
            string s=words2[i];
            vector<int> temp(125);
            for(int j=0;j<s.length();j++)
                temp[s[j]]++;
            
            for(int j=0;j<=124;j++)
                count[j]=max(count[j],temp[j]);
        }
        
        // for(int i=0;i<=255;i++)
        //     cout<<count[i]<<" ";
        
        vector<string> res;
        for(int i=0;i<words1.size();i++)
        {
            string word=words1[i];
            
            vector<int> count1(125);
            for(int j=0;j<word.size();j++)
                count1[word[j]]++;
            
//             for(int j=0;j<=124;j++)
//             cout<<count1[j]<<" ";
            
//             cout<<endl<<endl;
            
            bool flag=true;
            for(int j=0;j<=124;j++)
            {
                int x=count[j];
                int y=count1[j];
                
                if(x<=y)
                    continue;
                
                else
                {
                    flag=false;
                    break;
                }
            }
            
            if(flag)
               res.push_back(word); 
        }
        
        return res;
    }
};