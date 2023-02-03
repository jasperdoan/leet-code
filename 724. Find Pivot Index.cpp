class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, rightSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            rightSum += nums[i];
        }

        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};