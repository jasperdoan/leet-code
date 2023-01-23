/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int prefixMod = 0, result = 0;                  // prefixMod is the prefix sum mod k
                                                        // result is the number of subarrays divisible by k
        vector<int> modGroups(k);                       // modGroups[i] is the number of prefixMod equals to i
        modGroups[0] = 1;                               // Case when prefixMod is 0, there is one subarray divisible by k

        for (int num : nums) {                          // Iterate through the array
            prefixMod = (prefixMod + num % k + k) % k;  //   prefixMod = the prefix sum mod k (add k to make sure it is positive)
            result += modGroups[prefixMod];             //   result += the number of prefixMod equals to prefixMod
            modGroups[prefixMod]++;                     //   Increment the modGroups[prefixMod] by 1 
        }

        return result;
    }
    // Walkthrough:
    // nums = [4,5,0,-2,-3,1], k = 5
    // prefixMod = 0, result = 0, modGroups = [1,0,0,0,0]
    // num = 4, prefixMod = (0 + 4 % 5 + 5) % 5 = 4, result = 0, modGroups = [1,0,0,0,1]
    // num = 5, prefixMod = (4 + 5 % 5 + 5) % 5 = 4, result = 1, modGroups = [1,0,0,0,2]
    // num = 0, prefixMod = (4 + 0 % 5 + 5) % 5 = 4, result = 3, modGroups = [1,0,0,0,3]
    // num = -2, prefixMod = (4 + -2 % 5 + 5) % 5 = 2, result = 3, modGroups = [1,0,1,0,3]
    // num = -3, prefixMod = (2 + -3 % 5 + 5) % 5 = 4, result = 3, modGroups = [1,0,1,0,4]
    // num = 1, prefixMod = (4 + 1 % 5 + 5) % 5 = 0, result = 7, modGroups = [2,0,1,0,4]
    // return 7

    // Time Complexity: O(N), where N is the length of nums
    // Space Complexity: O(K), where K is the value of k
};
// @lc code=end

