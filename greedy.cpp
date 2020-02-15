#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> a;

int main() {
    cin >> m >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> res;
    for (int i = n - 1; i >= 0; --i) {
        if (m >= a[i]) {
            m -= a[i];
            res.push_back(i);
        }
    }
    reverse(begin(res), end(res));
    cout << res.size() << endl;
    for (int i : res) cout << i << ' ';
    cout << endl;
    return 0;
}