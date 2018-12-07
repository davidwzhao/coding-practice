#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[105];
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int opt[3][105];

    opt[0][0] = 0;
    opt[1][0] = 0;
    opt[2][0] = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            opt[0][i] = max(max(opt[0][i-1], opt[1][i-1]), opt[2][i-1]);
            opt[1][i] = 0;
            opt[2][i] = 0;
        } else if (a[i] == 1) {
            opt[0][i] = max(max(opt[0][i-1], opt[1][i-1]), opt[2][i-1]);
            opt[1][i] = max(opt[0][i-1], opt[2][i-1]) + 1;
            opt[2][i] = -100;
        } else if (a[i] == 2) {
            opt[0][i] = max(max(opt[0][i-1], opt[1][i-1]), opt[2][i-1]);
            opt[1][i] = -100;
            opt[2][i] = max(opt[0][i-1], opt[1][i-1]) + 1;
        } else {
            opt[0][i] = max(max(opt[0][i-1], opt[1][i-1]), opt[2][i-1]);
            opt[1][i] = max(opt[0][i-1], opt[2][i-1]) + 1;
            opt[2][i] = max(opt[0][i-1], opt[1][i-1]) + 1;
        }
    }

    cout << n - max(max(opt[0][n], opt[1][n]), opt[2][n]) << endl;
}
