class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};

// Walk through of the code: string s = "A man, a plan, a canal: Panama"
// 1. i = 0, j = 29
// 2. !isalnum(s[i]) = false (s[i] = 'A'), !isalnum(s[j]) = false (s[j] = 'a').
// 3. tolower(s[i]) = 'a', tolower(s[j]) = 'a'. Continue.