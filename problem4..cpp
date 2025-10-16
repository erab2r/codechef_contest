#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        int maxA = 0;
        for (int &x : A) {
            cin >> x;
            maxA = max(maxA, x);
        }

        vector<int> count(maxA + 2, 0);
        for (int x : A) count[x]++;

        vector<int> divCount(maxA + 2, 0);

        // For each number in array, increment multiples in divCount
        for (int i = 1; i <= maxA; i++) {
            if (count[i] == 0) continue;
            for (int j = i; j <= maxA; j += i) {
                divCount[j] += count[i];
            }
        }

        int answer = 0;
        // Try candidate Z from maxA down to 1
        for (int Z = maxA; Z >= 1; Z--) {
            if (N - divCount[Z] >= 2) { // at least two numbers are not divisible by Z
                answer = Z;
                break;
            }
        }

        cout << answer << "\n";
    }
    return 0;
}
