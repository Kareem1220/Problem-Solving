class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    { 
        int left = 0;
        int right = left + 1;
        int longest = 1;
        if(s.size() == 0) return 0;

        while(right < s.size())
        {
            int i = left;
            while(s[right] != s[i]) i++; 
            if(i != right) left = i+1;

            longest = max(longest, right - left + 1); 
            right++;
        }
        return longest;
    }
};
