#include <cstdio>

long long factorialCache[10000];

long long factorial(long long n) {

    long long returnValue;

    if (n == 0 || n == 1) {
        returnValue = 1;
    } else {
        if (factorialCache[n] != -1) {
            returnValue = factorialCache[n];
        } else {
            returnValue = n * factorial(n - 1);
        }
    }
    
    factorialCache[n] = returnValue;
    
    return returnValue;
}

long long nChooseR (long long n, long long r) {
    
    long long fraction = 1;
    for (int i = r + 1; i <= n; i++) {
        fraction *= i;
    }
    
    return (fraction/factorial(n - r));
}

int main () {

    for (int i = 0; i < 1000; i++) {
        factorialCache[i] = -1;
    }

    int numValues = 0;
    int numQueries = 0;
    long long values[10005];
    
    int l, r, k;
    
    for (int i = 0; i < 10005; i++) {
        values[i] = 0;
    }
    
    scanf ("%d %d", &numValues, &numQueries);
    
    for (int i = 0; i < numValues; i++) {
        scanf ("%d", &values[i]);
    }
    
    for (int i = 0; i < numQueries; i++) {
        scanf ("%d %d %d", &l, &r, &k);
        
        for (int j = l; j <= r; j++) {
            // values[j - 1] += (factorial(j - l + k))/(factorial(k) * factorial(j - l));
            values[j - 1] += nChooseR(j - l + k, k);
        }
    }
    
    for (int i = 0; i < numValues; i++) {
        printf ("%d ", values[i] % 100000007);
    }
    
    printf ("\n");
    
    return 0;
}
