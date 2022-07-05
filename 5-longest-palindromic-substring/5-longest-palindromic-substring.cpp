class Solution {
public:
    //Start of longest palindromic Substring
    int start;
    
    //Length of longest palindromic Substring
    int length;
    
    //Expand Around Center
    string longestPalindrome(string s) 
    {
        int n=s.length();
        //If string is of length 0 or 1 then it is a palindrome
        if(n<2)
            return s;
        
        //We will expand around centers from i=0 to i=n-1 
        for(int i=0;i<n;i++)
        {
            //For odd length strings middle character will be a palindrome
            //We need to expand from that middle character towards left and right
            //racecar
            expand(s,i,i);
            
            //For even length strings there will be two middle characters
            //We need to expand from first char to left and from second char to right
            //aabbaa
            expand(s,i,i+1);
        }
        
        return s.substr(start,length);
    }

    void expand(string s,int i,int j)
    {
        //Simple algorithm to check the expanse of Palindrome
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            i--;
            j++;
        }
        //After loop breaks i will be less than one and j will be greater than one what they need to be
        //So length of subarray = J-I+1
        //OR                    = (j-1)-(i+1)+1
        //Which                 = j-i-1
        int newlength=(j-1)-(i+1)+1;
        if(length<newlength)
        {
            //Here start=i+1 because after loop breaks i will be less than one what it need to be
            start=i+1;
            length=newlength;
        }
        return;
    }
    
    
};