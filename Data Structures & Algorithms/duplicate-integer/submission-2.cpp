class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        std::unordered_map<int , int> mp;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if( mp.find(nums[i]) != mp.end() )
            {
                return true;
            }
            else 
            {
            mp[nums[i]]= i;
            }
        }
        return false; 
        
    
    }
};