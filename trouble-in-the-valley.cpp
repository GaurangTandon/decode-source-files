#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 5;
long long buggySolution(char s[MAXN]) {
    int ones[MAXN];
    int oneCount = 0;

    for (long long i = 0; i < strlen(s); i++) {
        if (s[i] == '1') {
            ones[oneCount++] = i;
        }
    }

    long long n = oneCount, idx = -1, ma = 0;

    for (long long i = 0; i < n - 2; i++) {
        long long first = ones[i], middle = ones[i + 1], last = ones[i + 2];

        long long add = (last - first - 1);
        add *= add;

        long long gap1 = (middle - first - 1), gap2 = (last - middle - 1),
                  sub = gap1 * gap1 + gap2 * gap2, diff = add - sub;

        if (diff > ma) {
            ma = diff;
            idx = middle;
        }
    }

    return idx;
}

int main(void) {
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    char s[MAXN];
    scanf("%s", s);

    printf("%d", buggySolution(s));
}