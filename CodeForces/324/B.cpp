#include <iostream>

#define N 1000000007

using namespace std;

long long pow(int a, int n) {
    long long ans = 1;
    
    for (int i = 0; i < n; i++) {
        ans = (ans * a) % N;
    }
    
    return ans;
}

long long min(long long a, long long b) {
    if (a - b < 0) {
        return a - b + N;
    } else {
        return a - b;
    }
}

int main() {
    int n;
    cin >> n;
    
    cout << min(pow(27, n), pow(7, n)) << endl;
    
    return 0;
}