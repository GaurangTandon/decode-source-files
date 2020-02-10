#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;

    string ans = "";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            ans += "*"; 
        }
        
        ans += "\n";
    }

    cout << ans;
}
