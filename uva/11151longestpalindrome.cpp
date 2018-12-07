#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    string a;
    getline(cin, a);

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        int l = s.length();

        if (l == 0) {
            cout << 0 << endl;
            continue;
        }

        int opt[l][l];

        for (int j = 0; j < l; j++) {
            for (int k = 0; k < l; k++) opt[j][k] = 10000;
        }

        for (int j = 0; j < l - 1; j++) {
            opt[j][j] = 0;
            opt[j][j + 1] = (s[j] == s[j + 1]) ? 0 : 1;
        }

        opt[l - 1][l - 1] = 0;

        for (int j = l - 1; j >= 0; j--) {
            for (int k = j + 2; k < l; k++) {
                if (j >= k) continue;

                if (s[j] == s[k]) {
                    opt[j][k] = opt[j + 1][k - 1];
                } else {
                    opt[j][k] = min(opt[j + 1][k], opt[j][k - 1]) + 1;
                }

                // cout << opt[j][k] << " ";
            }
            // cout << endl;
        }

        cout << l - opt[0][l - 1] << endl;

        // if (i < n - 1) cout << endl;
    }

    return 0;
}
