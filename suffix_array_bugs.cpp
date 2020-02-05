#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
   public:
    string s;
    int n, __log_n;
    vector<int> sa;            // Suffix Array
    vector<vector<int>> ra;    // Rank Array
    vector<vector<int>> _lcp;  // Longest Common Prefix
    vector<int> __msb, __dollar;

    SuffixArray(string st) {
        n = st.size();
        __log_n = log2(n) + 1;
        ra = vector<vector<int>>(__log_n, vector<int>(n));
        sa = vector<int>(n);

        __msb = vector<int>(n);
        int mx = -1;
        for (int i = 0; i < n; i++) {
            if (i >= (1 << (mx + 1)))
                mx++;
            __msb[i] = mx;
        }
        this->s = st;
        build_SA();
    }

    void __counting_sort(int l, int k) {
        int maxi = max(300, n);
        vector<int> count(maxi, 0), temp_sa(n, 0);
        for (int i = 0; i < n; i++) {
            int idx = (i + k < n ? ra[l][i + k] : 0);
            count[idx]++;
        }
        for (int i = 0, sum = 0; i < maxi; i++) {
            int t = count[i];
            count[i] = sum;
            sum += t;
        }
        for (int i = 0; i < n; i++) {
            int idx = sa[i] + k < n ? ra[l][sa[i] + k] : 0;
            temp_sa[count[idx]++] = sa[i];
        }
        sa = temp_sa;
    }

    void build_SA() {
        for (int i = 0; i < n; i++)
            ra[0][i] = s[i];
        for (int i = 0; i < n; i++)
            sa[i] = i;
        for (int i = 0; i < __log_n - 1; i++) {
            int k = (1 << i);
            if (k >= n)
                break;
            __counting_sort(i, k);
            __counting_sort(i, 0);
            int rank = 0;
            ra[i + 1][sa[0]] = rank;
            for (int j = 1; j < n; j++)
                if (ra[i][sa[j]] == ra[i][sa[j - 1]] &&
                    ra[i][sa[j] + k] == ra[i][sa[j - 1] + k])
                    ra[i + 1][sa[j]] = rank;
                else
                    ra[i + 1][sa[j]] = ++rank;
        }
    }
};

int main() {
    string ques;
    cin >> ques;
    int n = ques.size();
    SuffixArray sa(ques);
    for (int i = 0; i < n; i++) {
        cout << sa.sa[i] << " ";
    }
    cout << endl;
    return 0;
}