#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, y;
    
    cin >> n;
    
    int rx[55], ry[55];
    vector<int> done;
    
    for (int i = 0; i < 55; i++) {
        rx[i] = 0;
        ry[i] = 0;
    }
    
    for (int i = 1; i <= n * n; i++) {
        cin >> x >> y;
        
        if (rx[x] == 1 || ry[y] == 1) continue;
        else {
            done.push_back(i);
            rx[x] = 1;
            ry[y] = 1;
        }
    }
    
    for (vector<int>::iterator it = done.begin(); it != done.end(); it++) {
        cout << *it << " ";
    }
    
    cout << endl;
    
    return 0;
}