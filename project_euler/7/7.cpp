#include <iostream>

using namespace std;

bool *primes = new bool[120005];

void sieve () {
    int i = 2;
    while (i < 120005) {
        int p = i;
        while (p <= 120005) {
            p += i;
            primes[p] = true;
        }
        
        for (int j = i + 1; true; j++) {
            if (!primes[j]) {
                i = j;
                break;
            }
        }
    }
}

int main () {    
    sieve();
    
    int i = 0;
    int j = 1;
    
    while (i < 10001) {
        j++;
        if (!primes[j]) i++;
        cout << j << " " << primes[j] << endl;
    }
    
    cout << j << endl;
    
    return 0;
}