class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = mergeSortedArrays(nums1, nums2);
        int size = result.size();
        if (size % 2 == 0) {
            return (result[size / 2 - 1] + result[size / 2]) / 2.0;
        } else {
            return result[size / 2];
        }
    }

    vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            result.push_back(nums2[j]);
            j++;
        }
        return result;
    }
};