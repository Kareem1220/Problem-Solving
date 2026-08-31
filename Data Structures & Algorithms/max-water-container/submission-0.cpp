class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int left = 0;
        int right = heights.size() - 1;
        int length = right - left;
        int width = min(heights[right], heights[left]);
        int maxArea = 0;
        while(left < right)
        {
             int length = right - left;
             int width = min(heights[right], heights[left]);
             maxArea = max(maxArea , width * length);
             if(heights[left] < heights[right]) left++;
             else right --;
        }
        return maxArea;
    }
};
