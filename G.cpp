#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string ss;
        cin >> n >> ss;
        int z = 0, one_val = 0;
        for (char c : ss) {
            if (c == '0') 
                z++;
            else 
                one_val++;
        }
        int turn = min(z, one_val);
        if (turn % 2 == 1)
            cout << "Zlatan\n";
        else
            cout << "Ramos\n";
    }

    return 0;
}
