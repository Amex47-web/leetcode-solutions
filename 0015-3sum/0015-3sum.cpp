class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            if (i && a[i] == a[i - 1]) continue;

            int l = i + 1, r = n - 1;

            while (l < r) {
                int s = a[i] + a[l] + a[r];

                if (s == 0) {
                    ans.push_back({a[i], a[l], a[r]});
                    l++;
                    r--;

                    while (l < r && a[l] == a[l - 1]) l++;
                    while (l < r && a[r] == a[r + 1]) r--;
                }
                else if (s < 0) l++;
                else r--;
            }
        }

        return ans;
    }
};