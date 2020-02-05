#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    int n;
    cin >> n;
    string wth;
    cin >> wth;
    // input ends here

    int up = 0;
    int right = 0;
    vector<pair<int, int>> dir;

    for (int i = 0; i < n; ++i) {
        if (wth[i] == 'U')
            up++;
        if (wth[i] == 'D')
            up--;
        if (wth[i] == 'L')
            right--;
        if (wth[i] == 'R')
            right++;
        if (i != n - 1)
            dir.push_back({up, right});
    }
    dir.push_back({0, 0});
    int dx = x2 - x1;
    int dy = y2 - y1;
    int day = INT_MAX;

    long long start = 1;
    long long end = 1e18;
    long long ans = 1e18;
    bool flag = false;

    while (start < end) {
        long long mid = start + (end - start) / 2;
        long long ind = mid % n;

        if (ind == 0)
            ind = n - 1;
        else
            ind -= 1;

        long long upar = (up * mid) / n;
        upar += dir[ind].first;

        long long bai = (right * mid) / n;
        bai += dir[ind].second;

        long long nox = bai + x1;
        long long noy = upar + y1;

        long long com1 = abs(nox - x2);
        long long com2 = abs(noy - y2);

        if (com1 + com2 <= mid) {
            flag = true;
            ans = min(ans, mid);
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    if (flag)
        cout << start << endl;
    else
        cout << -1 << endl;

    return 0;
}