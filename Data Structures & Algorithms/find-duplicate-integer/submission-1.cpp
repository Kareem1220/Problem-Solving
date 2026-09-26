class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size() - 1; 
        int count = 0; 
        for(int i = 0 ; i < nums.size() ; i++)
        {
            count++;
            for(int j = i + 1 ; j < nums.size() ; j++)
            {
                if(nums[j] == nums[i])
                {
                    count++;
                }
            }
            if(count > 1) return nums[i];
            else count = 0;
        }  
        return -1; 
    }
};
