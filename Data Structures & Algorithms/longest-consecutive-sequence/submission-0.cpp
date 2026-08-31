class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;
        int maxi = 0;
        std::unordered_set<int> st(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(st.find(nums[i] - 1 ) != st.end())
            {
                continue;
            }
            int start = nums[i];
            int length = 1;
            while(st.find(start + 1) != st.end())
            {
                start++;
                length++;
            }
            maxi = max( maxi,length);
        }
        return maxi; 
    }
};
