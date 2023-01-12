#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            difference = target - nums[i]
            if difference in hashmap:
                return [i, hashmap[difference]]
            hashmap[nums[i]] = i
        
# @lc code=end

