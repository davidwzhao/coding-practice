#include <iostream>

using namespace std;

int main() {
    int n, t;
    
    cin >> n >> t;
    
    if (t == 10 && n == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    if (t == 10) {
        cout << 1;
        for (int i = 0; i < n - 1; i++) {
            cout << 0;
        }
        cout << endl;
        return 0;
    }
    
    cout << t;
    for (int i = 0; i < n - 1; i++) {
        cout << 0;
    }
    
    cout << endl;
    
    return 0;
}