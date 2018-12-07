#include <iostream>

using namespace std;

bool primes[30];
int factors[30];

void sieve () {
    int i = 2;
    while (i < 30) {
        int p = i;
        while (p < 30) {
            p += i;
            primes[p] = true;
        }
        
        for (int j = i + 1; i < 30; j++) {
            if (!primes[j]) {
                i = j;
                break;
            }
        }
    }
}

void primeFactorize (int n) {
    for (int i = 0; i < 30; i++) factors[i] = 0;
    
    for (int i = 2; i < 30; i++) {
        if (!primes[i]) {
            while (n % i == 0) {
                n /= i;
                factors[i]++;
            }
        }
    }
}

int pow (int b, int e) {
    int num = 1;
    for (int i = 0; i < e; i++) {
        num *= b;
    }
    
    return num;
}

int main () {
    int num = 1;
    int used[30];
    
    for (int i = 0; i < 30; i++) used[i] = 0;
    
    sieve();
    
    for (int i = 1; i <= 20; i++) {
        
        primeFactorize(i);
        
        for (int j = 2; j < 30; j++) {
            if (factors[j] != 0) {
                if (factors[j] > used[j]) {
                    num *= pow(j, factors[j] - used[j]);
                    used[j] = factors[j];
                }
            }
        }
    }
    
    cout << num << endl;
    
    return 0;
}