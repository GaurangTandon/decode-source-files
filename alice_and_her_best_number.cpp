#include <bits/stdc++.h>
using namespace std;

int Solution(int a[]) {
    int i, k, j, l;
    int count1 = 0, count2 = 0, count = 0, count3 = 0;

    for (i = 0; i < 4; i++) {
        count1 = 0, count2 = 0;

        for (j = 0; j < 4; j++) {
            if (i == j)
                continue;
            if (a[i] >= 2 * a[j])
                count1++;
            if (2 * a[i] <= a[j])
                count2++;
        }

        if (count1 == 3) {
            count++;
            k = i;
        }

        if (count2 == 3) {
            count3++;
            l = i;
        }
    }

    if (count3 == 1)
        k = l;

    if (count > 1 && count3 > 1)
        k = 1;

    return a[k];
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x[] = {a, b, c, d};
    cout << Solution(x) << endl;
}