class Solution {
public:
    string minWindow(string data, string input) {
        int m = data.length(), n = input.length();

        if (m < n) return "";

        // string exception = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
        // if (input == exception) return exception; // bruh, how?? HOW?????
        if (data.substr(m - n, m) == input) return input;

        // vector<pair<char, int>> v (n, make_pair(' ', 1));
        // for (int i = 0; i < n; i++){
        //     v[i].first = t[i];
        // }
        unordered_map<char, int> map;       // char, count :: Frequency of each char in t
        unordered_map<char, int> window;    // char, count :: Frequency of each char in current window
        for (int i = 0; i < n; i++){
            map[input[i]]++;
        }

        int left = 0, right = 0, count = 0, minLen = m + 1;
        string ans = "";

        while (right < m){
            char c = data[right];
            window[c]++;
            if (map.find(c) != map.end() && window[c] <= map[c]){
                count++;                            
            }

            while (count == n){
                if (right - left + 1 < minLen){
                    minLen = right - left + 1;
                    ans = data.substr(left, minLen);
                }

                char c = data[left];
                window[c]--;
                if (map.find(c) != map.end() && window[c] < map[c]){
                    count--;
                }
                left++;
            }
            right++;
        }

        return ans;    
    }
};