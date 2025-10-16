#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> e(n);
        for (int i = 0; i < n; i++) 
            cin >> e[i];
        vector<int> h(n);
        for (int i = 0; i < n; i++) 
            cin >> h[i];
        map<int, pair<int,int>> mp; 
        for (int i = 0; i < n; i++) 
            mp[i] = {e[i], h[i]};
        int days_of_hpy = 0;
        for (int i=0;i<n;i++) {
            bool Alice = (h[i] <= 2 * e[i]);
            bool Bob  = (e[i] <= 2 * h[i]);
            if (Alice && Bob)
                days_of_hpy++;
        }
        cout << days_of_hpy << '\n';
    }
    
    return 0;
}
