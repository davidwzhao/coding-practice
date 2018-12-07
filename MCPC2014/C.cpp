#include <cstdio>

bool primes[1000005];

void sieve () {
    primes[0] = false;
    primes[1] = false;
    
    int n = 2;
    int i = 2;
    
    while (n < 1000000) {
        while (i < 1000000 / n) {
            primes[i * n] = false;
            i++;
        }
        
        n++;
        while (!primes[n]) {
            n++;
        }
        
        i = 2;
    }
}

int main () {

    for (int i = 0; i < 1000005; i++) {
        primes[i] = true;
    }
    
    sieve();
    
    int d, m, y, n;
    
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d/%d/%d", &d, &m, &y);
        
        int maxd = 31;
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            maxd = 30;
        } else if (m == 2) {
            maxd = 28;
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
                maxd = 29;
            }
        }
        
        d++;
        while (!primes[d] && d <= maxd) {
            d++;
        }
        
        if (d > maxd || !primes[m]) {
            m++;
            while (!primes[m] && m <= 12) {
                m++;
            }
            d = 2;
        }
        
        if (m > 12 || !primes[y]) {
            y++;
            while (!primes[y]) {
                y++;
            }
            m = 2;
            d = 2;
        }
        
        printf ("%02d/%02d/%d\n", d, m, y);
    }
    
    return 0;
}
