// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   void solve(int ind,vector<string>& ans,string s,unordered_set<string> m,vector<string> path)
   {
       if(ind==s.length())
       {
           string p=path[0];
           for(int i=1;i<path.size();i++)
           {
               p=p+" "+path[i];
           }
           
           ans.push_back(p);
           return;
       }
       
       for(int i=ind;i<s.length();i++)
       {
           if(m.find(s.substr(ind,i-ind+1))!=m.end())
           {
               string temp=s.substr(ind,i-ind+1);
               path.push_back(temp);
               solve(i+1,ans,s,m,path);
               path.pop_back();
           }
       }
   }
   
   vector<string> wordBreak(int n, vector<string>& dict, string s)
   {
       // code here
       unordered_set<string> m;
       for(int i=0;i<dict.size();i++)
       {
           m.insert(dict[i]);
       }
       
       vector<string> ans;
       vector<string> path;
       
       solve(0,ans,s,m,path);
       
       return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends