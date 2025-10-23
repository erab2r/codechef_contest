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
        vector<long long> arr(n);
        int even = 0, odd = 0;

        for (int i=0;i<n;i++) {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        bool same_val = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                same_val = false;
                break;
            }
        }

        if (same_val || even >= 2 || odd >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
