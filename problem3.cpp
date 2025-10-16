#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int h, e, s;
        cin >> h >> e >> s;
        vector<int> arr(h);
        for (int i=0;i<h;i++) 
            cin >> arr[i];
        sort(arr.rbegin(), arr.rend()); 
        for (int i = 0; i < s && i < h; i++)
            arr[i] = 0;
        e += 100 * s;
        int highest_score = 0;
        for (int score : arr)
            if (score > e)
                highest_score++;
        cout << highest_score + 1 << "\n";
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b, s;
        cin >> a >> b >> s;
        map<int, int, greater<int>> marks; 
        for (int i = 0; i < a; i++) {
            int x;
            cin >> x;
            marks[x]++; 
        }
        int cnt = 0;
        for (auto it = marks.begin(); it != marks.end() && cnt < s; ) {
            int num = it->first;
            int freq = it->second;
            while (freq-- && cnt < s) {
                cnt++;
            }
            it = marks.erase(it);
        }
        b += 100 * s;
        int total_values = 0;
        for (auto it = marks.begin(); it != marks.end(); it++) {
            int score = it->first;
            int freq = it->second;
            if (score > b) 
                total_values += freq;
            else break; 
        }

        cout << total_values + 1 << "\n"; 
    }

    return 0;
}

