class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
       std::vector<int> output(nums.size() , 1);
       std::vector<int> left(nums.size() , 1);
       std::vector<int> right(nums.size() , 1);
       int prefix = 1;
       for(int i = 0 ; i < nums.size() ; i++)
       {
        left[i] = prefix;
        prefix *= nums[i];
       }
       int suffix = 1;
       for(int i = nums.size() - 1  ; i >= 0 ; i--)
       {
        right[i] = suffix;
        suffix *= nums[i];
       }
       for(int i = 0 ; i < nums.size() ; i++)
       {
        output[i]=right[i] * left[i];
       }
       return output;
    }
};
