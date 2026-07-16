class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        int n = p.size();
        vector<pair<int,double>> a;

        for (int i = 0; i < n; i++)
            a.push_back({p[i], (double)(t - p[i]) / s[i]});

        sort(a.begin(), a.end());

        int ans = 0;
        double x = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (a[i].second > x) {
                ans++;
                x = a[i].second;
            }
        }

        return ans;
    }
};