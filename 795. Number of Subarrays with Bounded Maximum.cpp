class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0;
        int l = 0; // Left bound
        int r = 0; // Right bound

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > right) {
                l = i + 1;
                r = i + 1;
            } else if (nums[i] >= left) {
                r = i + 1;
            }
            res += r - l;
        }
        return res;
    }
};