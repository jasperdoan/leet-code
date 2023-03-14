class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> q1, q2, q3;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                q1.push(nums[i]);
            } else if (nums[i] == pivot) {
                q2.push(nums[i]);
            } else {
                q3.push(nums[i]);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!q1.empty()) {
                ans.push_back(q1.front());
                q1.pop();
            } else if (!q2.empty()) {
                ans.push_back(q2.front());
                q2.pop();
            } else {
                ans.push_back(q3.front());
                q3.pop();
            }
        }

        return ans;
    }
};