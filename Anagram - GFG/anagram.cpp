// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        
        vector<int> count(256);
        for(int i=0;i<a.size();i++)
        {
            char c=a[i];
            int x=c-97;
            
            count[x]++;
        }
        
        for(int i=0;i<b.size();i++)
        {
            char c=b[i];
            int x=c-97;
            
            count[x]--;
        }
        
        // for(auto i:count)
        // cout<<i<<' ';
        
        for(int i=0;i<256;i++)
        {
            if(count[i]!=0)
                return false;
        }
        
        return true;
        
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends