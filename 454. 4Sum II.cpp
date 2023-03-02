class Solution {
private:
    typedef unordered_map<int, int> umap;
    typedef vector<int> vec;
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        umap m1, m2;
        int ans = 0;

        const auto buildMap = [](const vec &v1, const vec &v2) -> umap {
            umap m;
            for (int i = 0; i < v1.size(); ++i) {
                for (int j = 0; j < v2.size(); ++j) {
                    m[v1[i] + v2[j]]++;
                }
            }
            return m;
        };

        m1 = buildMap(nums1, nums2);
        m2 = buildMap(nums3, nums4);

        for (auto &p : m1) {
            int complement = -p.first;
            if (m2.find(complement) != m2.end()) {
                ans += p.second * m2[complement];
            }
        }

        return ans;
    }
};