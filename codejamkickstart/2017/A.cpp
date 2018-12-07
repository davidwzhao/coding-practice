#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long mod = 10e9 + 7;

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        int nums[10005];

        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }

        long long sum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // cout << nums[k] - nums[j] << " " << (int) pow(2, k - j - 1) << endl;
                sum = (sum + (nums[k] - nums[j]) * (int) pow(2, k - j - 1)) % mod;
            }
        }

        cout << "Case #" << i + 1 << ": " << sum << endl;
    }
}
