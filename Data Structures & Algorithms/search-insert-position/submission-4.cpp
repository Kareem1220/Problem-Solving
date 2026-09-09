class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0; 
        int right = nums.size() - 1;
        int mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(target == nums[mid]) return mid;
            else if(target > nums[right]) return right + 1;
            else if(target <= nums[left]) return left;
            else if(target >  nums[mid])
            {
                left = mid + 1;
            }
            else if(target <  nums[mid]) 
            {
                right = mid - 1; 
            }
        }
        return mid;
    }
};