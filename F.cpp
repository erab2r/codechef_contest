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
        vector<int> e;
        for (int i = 1; i <= n; i += 4) {
            if (i + 3 <= n) {
                e.insert(e.end(), {i, i + 1, i + 3, i + 2});
            } else if (i + 2 <= n) {
                e.insert(e.end(), {i, i + 2, i + 1});
            } else if (i + 1 <= n) {
                e.insert(e.end(), {i, i + 1});
            } else {
                e.push_back(i);
            }
        }
        if (n == 6) 
            e = {1, 6, 2, 3, 5, 4};
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << e[i];
        }
        cout << '\n';
    }
    return 0;
}