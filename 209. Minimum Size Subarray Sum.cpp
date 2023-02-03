class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Use prefix sum
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        int ans = INT_MAX;
        int l = 0, r = 0;

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        while (r <= n) {
            if (prefix[r] - prefix[l] >= target) {
                ans = min(ans, r - l);
                l++;
            } else {
                r++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};