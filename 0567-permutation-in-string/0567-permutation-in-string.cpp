class Solution {
public:
    bool checkInclusion(string a, string b) {
        int n = a.size(), m = b.size();
        if (n > m) return false;

        vector<int> x(26), y(26);

        for (char c : a) x[c - 'a']++;

        for (int i = 0; i < m; i++) {
            y[b[i] - 'a']++;

            if (i >= n)
                y[b[i - n] - 'a']--;

            if (x == y)
                return true;
        }

        return false;
    }
};