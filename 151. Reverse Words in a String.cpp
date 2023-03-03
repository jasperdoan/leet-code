class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        // Split the string into words
        int i = 0;
        while (i < s.size()) {
            // Skip the spaces
            while (i < s.size() && s[i] == ' ') i++;
            if (i >= s.size()) break;

            // Get a word
            int j = i + 1;
            while (j < s.size() && s[j] != ' ') j++;
            words.push_back(s.substr(i, j - i));
            i = j + 1;
        }

        // Reverse the words
        reverse(words.begin(), words.end());

        // Join the words
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }
        return result;
    }
};