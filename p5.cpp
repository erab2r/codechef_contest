#include <bits/stdc++.h>
using namespace std;

/*
 Fast replacement for the recursive solution.

 Reason (short):
  - The recursive brute-force explores every deletion state (exponential).
  - Analysis shows the winning-first-move count (with the game rules you used)
    can be computed in linear time using prefix sums and a frequency map.
  - This program returns the same results as the recursive solver but in O(N).
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long total = accumulate(a.begin(), a.end(), 0LL);

        // If total <= 0 the fast logic yields 0 (same as recursive behavior for constraints)
        if (total <= 0) {
            cout << 0 << '\n';
            continue;
        }

        // Count number of subarrays whose sum == total
        // Using prefix sums: prefix[r] - prefix[l-1] == total  -> prefix[l-1] == prefix[r] - total
        unordered_map<long long, int> freq;
        freq.reserve(n*2);
        freq.max_load_factor(0.7f);

        long long pref = 0;
        freq[0] = 1;
        long long ans = 0;
        for (int x : a) {
            pref += x;
            auto it = freq.find(pref - total);
            if (it != freq.end()) ans += it->second;
            freq[pref] += 1;
        }

        cout << ans << '\n';
    }
    return 0;
}
