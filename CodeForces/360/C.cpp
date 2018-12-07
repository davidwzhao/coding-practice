#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int c[505];

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    int opt[505][505];

    for (int i = 0; i < 505; i++) {
        opt[i][0] = 0;
        opt[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= k; w++) {
            opt[i][w] = opt[i-1][w];
            for (int j = 0; j <= w - c[i]; j++) {
                if (opt[i-1][j] + c[i] > opt[i][w]) opt[i][w] = opt[i-1][j] + c[i];
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        // cout << opt[n][i] << " ";
        if (opt[n][i] == i && opt[n][k-i] == k - i) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
