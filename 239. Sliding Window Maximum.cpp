class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;    // key: num, value: count

        if (nums.empty() || k == 0) return res;

        for (int i = 0; i < k; i++) {
            m[nums[i]]++;
        }

        res.push_back(m.rbegin()->first);

        for (int i = k; i < nums.size(); i++) {
            m[nums[i]]++;
            m[nums[i - k]]--;

            if (m[nums[i - k]] == 0) 
                m.erase(nums[i - k]);

            res.push_back(m.rbegin()->first);
        }

        return res;
    }
    // nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
    // m = { -1:1 , 1:1 , 3:1 }
    // res = [3]        --> Because rbegin()->first 
    //                      returns last key in the container, and since map is sorted, it is the max value in the window
    // i = 3
    //                              m = { -1:1 , 1:1 , 3:1 }
    // m[nums[3]] = m[-3]++     ==> m = { -3:{1} , -1:1 , 1:1 , 3:1 }
    // m[nums[3 - k]] = m[1]--  ==> m = { -3:1 , -1:1 , 1:{0} , 3:1 }
    // if (m[nums[3 - k]] == 0) ==> m = { -3:1 , -1:1 , 3:1 }
    // res.push_back(m.rbegin()->first) ==> res = [3, 3]
    //
    // i = 4
    //                              m = { -3:1 , -1:1 , 3:1 }
    // m[nums[4]] = m[5]++      ==> m = { -3:1 , -1:1 , 3:1 , 5:1 }
    // m[nums[4 - k]] = m[3]--  ==> m = { -3:1 , -1:1 , 3:0 , 5:1 }
    // if (m[nums[4 - k]] == 0) ==> m = { -3:1 , -1:1 , 5:1 } 
    // res.push_back(m.rbegin()->first) ==> res = [3, 3, 5]
    //
    // i = 5
    //                              m = { -3:1 , -1:1 , 5:1 }
    // m[nums[5]] = m[3]++      ==> m = { -3:1 , -1:1 , 3:1 , 5:1 }
    // m[nums[5 - k]] = m[-1]-- ==> m = { -3:1 , -1:0 , 3:1 , 5:1 }
    // if (m[nums[5 - k]] == 0) ==> m = { -3:1 , 3:1 , 5:1 }
    // res.push_back(m.rbegin()->first) ==> res = [3, 3, 5, 5]
    //
    // i = 6
    //                              m = { -3:1 , 3:1 , 5:1 }
    // m[nums[6]] = m[6]++      ==> m = { -3:1 , 3:1 , 5:1 , 6:1 }
    // m[nums[6 - k]] = m[-3]-- ==> m = { -3:0 , 3:1 , 5:1 , 6:1 }
    // if (m[nums[6 - k]] == 0) ==> m = { 3:1 , 5:1 , 6:1 }
    // res.push_back(m.rbegin()->first) ==> res = [3, 3, 5, 5, 6]
    //
    // etc...
    //
    // res = [3, 3, 5, 5, 6, 7]
};