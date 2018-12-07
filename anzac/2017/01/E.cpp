#include <iostream>

using namespace std;

int main() {
    long long t[1005][1005];

    long long n, p;
    cin >> n >> p;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    t[1][1] = 1;
    t[2][1] = 1;

    for (int i = 3; i <= n; i++) {
        t[i][i - 1] = 1;
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i - 1; j++) {
            t[i][j] = (t[i - 1][j] * j) % p;
        }
    }

    long long sum = 0;
    for (int i = 1; i < n; i++) {
        cout << t[n][i] << endl;
        sum = (sum + t[n][i]) % p;
    }

    cout << sum << endl;
}
