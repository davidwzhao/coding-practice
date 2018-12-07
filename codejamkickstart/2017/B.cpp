#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {

        double x[10005];
        double y[10005];
        double w[10005];

        int n = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> x[j] >> y[j] >> w[j];
        }

        // find center
        double x_sum = 0, y_sum = 0, w_sum = 0;
        for (int j = 0; j < n; j++) {
            x_sum += x[j] * w[j];
            y_sum += y[j] * w[j];
            w_sum += w[j];
        }

        double xx = w_sum > 0 ? x_sum / w_sum : 0;
        double yy = w_sum > 0 ? y_sum / w_sum : 0;

        cout << xx << " " << yy << endl;

        // compute dists
        double dist = 0;
        for (int j = 0; j < n; j++) {
            dist += w[j] * max(abs(xx - x[j]), abs(yy - y[j]));
        }

        cout << "Case #" << i + 1 << ": " << dist << endl;
    }
}
