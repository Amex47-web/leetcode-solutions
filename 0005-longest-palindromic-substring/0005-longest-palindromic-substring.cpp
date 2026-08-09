class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), l = 0, r = 0;

        auto f = [&](int i, int j) {
            while (i >= 0 && j < n && s[i] == s[j]) {
                i--;
                j++;
            }
            return j - i - 1;
        };

        for (int i = 0; i < n; i++) {
            int a = f(i, i), b = f(i, i + 1);
            int x = max(a, b);

            if (x > r - l + 1) {
                l = i - (x - 1) / 2;
                r = i + x / 2;
            }
        }

        return s.substr(l, r - l + 1);
    }
};