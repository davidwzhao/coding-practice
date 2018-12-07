#include <iostream>

using namespace std;

int main () {
    int cells[30005];
    int n, target;
    
    cin >> n;
    cin >> target;
    
    for (int i = 1; i < n; i++) {
        cin >> cells[i];
    }
    
    int i = 1;
    while (i < target && i <= n) {
        i += cells[i];
    }
    
    if (i == target) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}