class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int left = 0, right = numbers.size() - 1;

        while (left < right){
            if (numbers[left] + numbers[right] > target) right--;
            else if (numbers[left] + numbers[right] < target) left++;
            else{
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};