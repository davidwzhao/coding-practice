#include <iostream>

using namespace std;

int main () {
    int s1 = 0, s2 = 0;
    
    for (int i = 1; i <= 100; i++) {
        s1 += i;
        s2 += i * i;
    }
    
    s1 *= s1;
    
    cout << s2 - s1 << endl;
    
    return 0;
}