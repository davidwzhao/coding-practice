#include <cstdio>

long long *factors (long long n) {

    long long fac[10000];
    
    int j = 0;
    for (long long i = n; i > 0; i--) {
        if (n % i == 0) {
            fac[j] = i;
            j++;
        }
    }
    
    return fac;
}

int main () {

    long long x, k;
    long long fac[1E12];
    
    scanf ("%I64d %I64d", &x, &k);
    
    if (k < 10E5) {
        for (int i = 0; i < k; i++) {
            
            
