class Solution {
public:
    vector<vector<int>> sol;
    vector<int> comb;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        backtrack(0,nums,target);
        return sol;
    }
    void backtrack(int start , vector<int>& nums , int target)
    {
        int sum = 0;
        for(int j = 0 ; j < comb.size() ; j++)
        {
           sum+= comb[j];
        }
        if(sum == target) 
        {
            sol.push_back(comb);
            return;
        }
        if(sum > target) return;
        for(int i = start ; i < nums.size() ; i++)
        {
            comb.push_back(nums[i]);
            backtrack(i , nums , target);
            comb.pop_back();
        } 
    }
};
