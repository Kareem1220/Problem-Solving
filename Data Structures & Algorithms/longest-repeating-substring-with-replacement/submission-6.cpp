class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        std::unordered_map<char, int> mp;
        int longest = 0;
        int left = 0; 
        int right = 0;
        int highest = 0;

        while(right < s.size())
        {
            mp[s[right]]++;
            highest = max(highest , mp[s[right]]);
            
            while((right - left + 1) - highest > k)
            {
                mp[s[left]]--;
                left++;
            }
            longest = max(longest, right - left + 1);
            right++;
        }

        longest = min<int>(longest, s.size());
        return longest;
    }
};