#include <iostream>
#include <cmath>

using namespace std;

int main () {

    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int b, c;
        cin >> b >> c;
        
        if (b == 0) {
            b = 1;
        }
        cout << "Case #" << i + 1 << ": " << (int) ceil ((float)b/c) << endl;
    }
    
    return 0;
}
