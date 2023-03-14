class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int range_s = 0, range_e = 0;

        if (nums.size() == 0) return ans;

        auto push = [&]() {
            if (range_s == range_e) {
                ans.push_back(to_string(range_s));
            } else {
                ans.push_back(to_string(range_s) + "->" + to_string(range_e));
            }
        };


        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                range_s = nums[i];
                range_e = nums[i];
            } else {
                if (nums[i] == range_e + 1) {
                    range_e = nums[i];
                } else {
                    push();
                    range_s = nums[i];
                    range_e = nums[i];
                }
            }
        }
        push();


        return ans;
    }
};