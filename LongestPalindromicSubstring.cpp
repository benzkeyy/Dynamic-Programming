// Question - https://leetcode.com/problems/longest-palindromic-substring
// Done using "expand along the center" concept!
    int palindrome(string s, int left, int right)
    {
        int l = left; int r = right;
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s) 
    {
        if(s.empty()) return string();
        int l1,l2,l,m=0,start=0;
        for(int i = 0; i < s.size(); i++)
        {
            l1 = palindrome(s,i,i);
            l2 = palindrome(s,i,i+1);
            l = max(l1,l2);
            if(l > m)
            {
                if(l & 1) // odd..
                    start = i - l/2;
                else
                    start = i - l/2 + 1;
                m = l;
            }
        }
        return s.substr(start,m);
    }
