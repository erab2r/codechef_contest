#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n + 1);
    for (int i = 0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int cnt = 0, mid = -1;
    for (int i = 1;i<= n;i++) {
        if ((int)adj_list[i].size() > 2) {
            cnt++;
            mid = i;
        }
    }
    if (cnt > 1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    if (cnt == 0) {
        int h = -1, e = -1;
        for (int i = 1; i <= n; i++) {
            if (adj_list[i].size() == 1) {
                if (h == -1) 
                    h = i;
                else 
                    e = i;
            }
        }
        cout << 1 << "\n";
        cout << h << " " << e << "\n";
        return 0;
    }
    vector<int> l;
    for (int i=1;i <= n;i++) {
        if (adj_list[i].size() == 1) {
            l.push_back(i);
        }
    }
    cout << l.size() << "\n";
    for (int lf_node : l) {
        cout << mid << " " << lf_node << endl;
    }

    return 0;
}
