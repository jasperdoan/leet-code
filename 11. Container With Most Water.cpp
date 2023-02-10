class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;

        while (l < r){
            int area = min(height[l], height[r]) * (r - l);
            maxArea = max(maxArea, area);
            
            height[l] < height[r] ? l++ : r--;
        }

        return maxArea;
    }
};